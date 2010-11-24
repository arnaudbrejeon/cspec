/*
 *  cspec_output_junit_xml.c   :  JUnit Xml output
 *
 * See copyright notice in cspec.h
 *
 */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cspec_output_junit_xml.h"
#include "cspec_private_output_junit_xml.h"

static CSpecOutputStruct xml;
static FILE *outputXmlFile = NULL;

static int n_descrOutputs;
static descrOutputs_t* descrOutputs;

void output_header(const char *encoding)
{
    fprintf(outputXmlFile, "<?xml version=\"1.0\" encoding=\"%s\" ?>\n", encoding);
    fprintf(outputXmlFile, "<testsuites>\n");
}
void output_footer()
{
    fprintf(outputXmlFile, "</testsuites>\n");
}
void output_describe_header(int i)
{
    int j;
    int n_failure = 0;

    for (j = 0; j < descrOutputs[i].n_itOutputs; ++j) {
        n_failure += descrOutputs[i].itOutputs[j].failures->size;
    }
    fprintf(outputXmlFile,
            "  <testsuite errors=\"0\" failures=\"%d\" name=\"%s\" tests=\"%d\">\n",
            n_failure,
            descrOutputs[i].descr,
            descrOutputs[i].n_itOutputs);
}
void output_it(int i, int j)
{
    int k;

    fprintf(outputXmlFile,
            "    <testcase name=\"%s\" assertions=\"%d\">\n",
            descrOutputs[i].itOutputs[j].descr,
            descrOutputs[i].itOutputs[j].n_assert - descrOutputs[i].itOutputs[j].n_pending);
    for (k = 0; k < descrOutputs[i].itOutputs[j].failures->size; ++k) {
        const failure_t* const p = array_get_element(descrOutputs[i].itOutputs[j].failures, k);

        fprintf(outputXmlFile,
                "      <failure message=\"%s\" type=\"%s\">\n",
                p->message,
                p->type);
        fprintf(outputXmlFile,
                "%s:%d: %s\n",
                p->fname,
                p->line,
                p->assertion_descr);
        fprintf(outputXmlFile, "      </failure>\n");
    }
    fprintf(outputXmlFile, "    </testcase>\n");
}
void output_describe_footer()
{
    fprintf(outputXmlFile, "  </testsuite>\n");
}

void CSpec_JUnitXmlFileOpen(const char *filename, const char *encoding)
{
	time_t	timeValue;
	char*	timeStr;

	outputXmlFile = fopen(filename, "w");

	if (outputXmlFile == NULL)
	{
		return;
	}

	time(&timeValue);
	timeStr = ctime(&timeValue);
	timeStr[strlen(timeStr) - 1] = '\0';

	n_descrOutputs = 0;
	descrOutputs = NULL;

	output_header(encoding);
}

void CSpec_JUnitXmlFileClose(void)
{
    int i;
    int j;

	if (outputXmlFile == NULL)
	{
		return;
	}

	for (i = 0; i < n_descrOutputs; ++i) {
        output_describe_header(i);
        for (j = 0; j < descrOutputs[i].n_itOutputs; ++j) {
            output_it(i, j);
        }
        output_describe_footer();
	}
	output_footer();

	for (i = 0; i < n_descrOutputs; ++i) {
        if (NULL != descrOutputs[i].itOutputs) {
            free(descrOutputs[i].itOutputs);
            descrOutputs[i].itOutputs = NULL;
        }
	}
	free(descrOutputs);
	descrOutputs = NULL;

	fclose(outputXmlFile);
}

void startDescribeFunJUnitXml(const char *descr)
{
	if (outputXmlFile == NULL)
	{
		return;
	}

	if (0 == (n_descrOutputs % N_DESCRIBE)) {
        descrOutputs_t* p = realloc(descrOutputs, (n_descrOutputs + N_DESCRIBE) * sizeof(descrOutputs_t));
        descrOutputs = p;
	}

	descrOutputs[n_descrOutputs].descr = descr;
	descrOutputs[n_descrOutputs].n_itOutputs = 0;
	descrOutputs[n_descrOutputs].itOutputs = NULL;

	++n_descrOutputs;
}

void endDescribeFunJUnitXml(void)
{
}

void startItFunJUnitXml(const char *descr)
{
	if (outputXmlFile == NULL)
	{
		return;
	}

	if (0 == (descrOutputs[n_descrOutputs - 1].n_itOutputs % N_IT)) {
        descrOutputs[n_descrOutputs - 1].itOutputs = realloc(descrOutputs[n_descrOutputs - 1].itOutputs,
                                                             (descrOutputs[n_descrOutputs - 1].n_itOutputs + N_IT) * sizeof(itOutputs_t));
	}

	descrOutputs[n_descrOutputs - 1].itOutputs[descrOutputs[n_descrOutputs - 1].n_itOutputs].n_assert = 0;
	descrOutputs[n_descrOutputs - 1].itOutputs[descrOutputs[n_descrOutputs - 1].n_itOutputs].n_pending = 0;
	descrOutputs[n_descrOutputs - 1].itOutputs[descrOutputs[n_descrOutputs - 1].n_itOutputs].descr = descr;
	descrOutputs[n_descrOutputs - 1].itOutputs[descrOutputs[n_descrOutputs - 1].n_itOutputs].failures = array_new(sizeof(failure_t));

	++(descrOutputs[n_descrOutputs - 1].n_itOutputs);
}

void endItFunJUnitXml()
{
}

void evalFunJUnitXml(const char *filename, int line_number, const char *assertion, int assertionResult)
{
	if (outputXmlFile == NULL)
	{
		return;
	}

	++(descrOutputs[n_descrOutputs - 1].itOutputs[descrOutputs[n_descrOutputs - 1].n_itOutputs - 1].n_assert);

	if(! assertionResult)
	{
        failure_t failure;
        failure.message = "Failed";
        failure.type = "";
        failure.fname = filename;
        failure.line = line_number;
        failure.assertion_descr = assertion;
        array_add(descrOutputs[n_descrOutputs - 1].itOutputs[descrOutputs[n_descrOutputs - 1].n_itOutputs - 1].failures, &failure);
	}
}

void pendingFunJUnitXml(const char* reason)
{
	if (outputXmlFile == NULL)
	{
		return;
	}

	++(descrOutputs[n_descrOutputs - 1].itOutputs[descrOutputs[n_descrOutputs - 1].n_itOutputs - 1].n_pending);
}

CSpecOutputStruct* CSpec_NewOutputJUnitXml()
{
	CSpec_InitOutput(&xml);
	
	xml.startDescribeFun	= startDescribeFunJUnitXml;
	xml.endDescribeFun		= endDescribeFunJUnitXml;
	xml.startItFun			= startItFunJUnitXml;
	xml.endItFun			= endItFunJUnitXml;
	xml.evalFun				= evalFunJUnitXml;
	xml.pendingFun			= pendingFunJUnitXml;

	return &xml;
}

