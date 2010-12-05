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
#include "cspec_output_junit_xml.h"
#include "cspec_private_output_junit_xml.h"

static CSpecOutputStruct xml;
static FILE *outputXmlFile = NULL;

static int n_descrOutputs;
static descrOutputs_t* descrOutputs;

void CSpec_JUnitXmlFileOpen(const char *filename, const char *encoding)
{
	outputXmlFile = fopen(filename, "w");

	if (outputXmlFile == NULL)
	{
		return;
	}

	n_descrOutputs = 0;
	descrOutputs = NULL;

	output_header(encoding);
}

void CSpec_JUnitXmlFileClose(void)
{
    int ret;

	if (outputXmlFile == NULL)
	{
		return;
	}

    output_describe();
	output_footer();

    destruct();

	ret = fclose(outputXmlFile);
    if (0 != ret) {
        fprintf(stderr, "[ERR] %s(%d) fclose() failed\n", __FILE__, __LINE__);
    }
}

void output_header(const char *encoding)
{
    fprintf(outputXmlFile, "<?xml version=\"1.0\" encoding=\"%s\" ?>\n", encoding);
    fprintf(outputXmlFile, "<testsuites>\n");
}
void output_footer()
{
    fprintf(outputXmlFile, "</testsuites>\n");
}
void output_describe()
{
    int i;

	for (i = 0; i < n_descrOutputs; ++i) {
        output_describe_header(descrOutputs + i);
        output_describe_main(descrOutputs + i);
        output_describe_footer();
	}
}
void output_describe_header(const descrOutputs_t* const descr)
{
    int n_failure = sumup_failure(descr);
    fprintf(outputXmlFile,
            "  <testsuite errors=\"0\" failures=\"%d\" name=\"%s\" tests=\"%d\">\n",
            n_failure,
            descr->descr,
            descr->n_itOutputs);
}
void output_describe_main(const descrOutputs_t* const descr)
{
    int j;

    for (j = 0; j < descr->n_itOutputs; ++j) {
        output_it(descr->itOutputs + j);
    }
}
void output_describe_footer()
{
    fprintf(outputXmlFile, "  </testsuite>\n");
}
int sumup_failure(const descrOutputs_t* const descr)
{
    int j;
    int sum = 0;

    for (j = 0; j < descr->n_itOutputs; ++j) {
        sum += descr->itOutputs[j].failures->size;
    }
    return sum;
}
void output_it(const itOutputs_t* const it)
{
    output_it_header(it);
    output_it_main(it);
    output_it_footer();
}
void output_it_header(const itOutputs_t* const it)
{
    fprintf(outputXmlFile,
            "    <testcase name=\"%s\" assertions=\"%d\">\n",
            it->descr,
            it->n_assert - it->n_pending);
}
void output_it_main(const itOutputs_t* const it)
{
    int k;

    for (k = 0; k < it->failures->size; ++k) {
        const failure_t* const fail = array_get_element(it->failures, k);

        fprintf(outputXmlFile,
                "      <failure message=\"%s\" type=\"%s\">\n",
                fail->message,
                fail->type);
        fprintf(outputXmlFile,
                "%s:%d: %s\n",
                fail->fname,
                fail->line,
                fail->assertion_descr);
        fprintf(outputXmlFile, "      </failure>\n");
    }
}
void output_it_footer()
{
    fprintf(outputXmlFile, "    </testcase>\n");
}

void destruct()
{
    int i;

    for (i = 0; i < n_descrOutputs; ++i) {
        destruct_descr(descrOutputs + i);
    }
	free(descrOutputs);
	descrOutputs = NULL;
}
void destruct_descr(descrOutputs_t* const descr)
{
    int j;

    if (NULL == descr) {
        return;
    }
    for (j = 0; j < descr->n_itOutputs; ++j) {
        destruct_it(descr->itOutputs + j);
    }
    free(descr->itOutputs);
    descrOutputs->itOutputs = NULL;
}
void destruct_it(itOutputs_t* const it)
{
    if (NULL == it) {
        return;
    }
    array_delete(&(it->failures));
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
        int ret;

        failure.message = "Failed";
        failure.type = "";
        failure.fname = filename;
        failure.line = line_number;
        failure.assertion_descr = assertion;
        ret = array_add(descrOutputs[n_descrOutputs - 1].itOutputs[descrOutputs[n_descrOutputs - 1].n_itOutputs - 1].failures, &failure);
        if (0 != ret) {
            fprintf(stderr, "[ERR] %s(%d) array_add() failed (ret=%d,descrOutputs=%p,n_descrOutputs=%d,itOutputs=%p,n_itOutputs=%d,failures=%p)\n",
                    __FILE__,
                    __LINE__,
                    ret,
                    descrOutputs,
                    n_descrOutputs,
                    descrOutputs[n_descrOutputs - 1].itOutputs,
                    descrOutputs[n_descrOutputs - 1].n_itOutputs,
                    descrOutputs[n_descrOutputs - 1].itOutputs[descrOutputs[n_descrOutputs - 1].n_itOutputs - 1].failures);
        }
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
