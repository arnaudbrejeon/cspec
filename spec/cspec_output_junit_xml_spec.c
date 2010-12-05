#include <stdio.h>
#include "cspec.h"
#include "cspec_output_junit_xml.h"
#include "cspec_private_output_junit_xml.h"

DESCRIBE(CSpec_NewOutputJUnitXml, "CSpecOutputStruct* CSpec_NewOutputJUnitXml()") {
    IT("returns not-NULL pointer") {
        SHOULD_NOT_BE_NULL(CSpec_NewOutputJUnitXml());
    } END_IT;

    IT("returns the struct which member is setted up") {
        SHOULD_NOT_BE_NULL(CSpec_NewOutputJUnitXml()->startDescribeFun);
        SHOULD_NOT_BE_NULL(CSpec_NewOutputJUnitXml()->endDescribeFun);
        SHOULD_NOT_BE_NULL(CSpec_NewOutputJUnitXml()->startItFun);
        SHOULD_NOT_BE_NULL(CSpec_NewOutputJUnitXml()->endItFun);
        SHOULD_NOT_BE_NULL(CSpec_NewOutputJUnitXml()->evalFun);
        SHOULD_NOT_BE_NULL(CSpec_NewOutputJUnitXml()->pendingFun);
        SHOULD_EQUAL(CSpec_NewOutputJUnitXml()->failed, 0);
    } END_IT;
} END_DESCRIBE;

FILE* fp;
void before(const char* const fname)
{
    fp = fopen(fname, "r");
}
void check(const char* const expect)
{
    if (NULL == fp) {
        SHOULD_PENDING("file not opened");
    }
    else {
        char buffer[1024];
        char* p;

        p = fgets(buffer, sizeof(buffer), fp);
        if (NULL == p) {
            SHOULD_PENDING("EOF");
        }
        else {
            SHOULD_MATCH(buffer, expect);
        }
    }
}
void after()
{
    if (NULL == fp) {
        return;
    }
    fclose(fp);
}

DESCRIBE(cspec_output_junit_xml_case1, "when 1 description with 1 'it' and 1 assertion done, 1 success") {
    CSpecOutputStruct* output_struct;
    const char* const fname = "output_cspec_output_junit_xml_case1.xml";

    output_struct = CSpec_NewOutputJUnitXml();
    CSpec_JUnitXmlFileOpen(fname, "utf-8");
    startDescribeFunJUnitXml("descr1");
    startItFunJUnitXml("it1");
    evalFunJUnitXml("fname", 100, "assertion1", 1);
    endItFunJUnitXml();
    endDescribeFunJUnitXml();
    CSpec_JUnitXmlFileClose();

    before(fname);
    IT("output header") {
        check("<?xml version=\"1.0\" encoding=\"utf-8\" ?>\n");
    } END_IT;
    IT("output testsuites start tag") {
        check("<testsuites>\n");
    } END_IT;
    IT("output testsuite start tag with error=0, failure=0, tests=1") {
        check("  <testsuite errors=\"0\" failures=\"0\" name=\"descr1\" tests=\"1\">\n");
    } END_IT;
    IT("output testcase with assertion=1") {
        check("    <testcase name=\"it1\" assertions=\"1\">\n");
        check("    </testcase>\n");
    } END_IT;
    IT("output testsuite end tag") {
        check("  </testsuite>\n");
    } END_IT;
    IT("output testsuites end tag") {
        check("</testsuites>\n");
    } END_IT;
    after();
} END_DESCRIBE;

DESCRIBE(cspec_output_junit_xml_case2, "when 2 description with 3 'it' and 4 assertion done, 2 success and 1 failure and 1 pending") {
    CSpecOutputStruct* output_struct;
    const char* const fname = "output_cspec_output_junit_xml_case2.xml";

    output_struct = CSpec_NewOutputJUnitXml();
    CSpec_JUnitXmlFileOpen(fname, "shift-jis");
    startDescribeFunJUnitXml("descr1");
    startItFunJUnitXml("it1-1");
    evalFunJUnitXml("fname", 11, "assertion1", 1);
    endItFunJUnitXml();
    startItFunJUnitXml("it1-2");
    evalFunJUnitXml("fname", 12, "assertion2", 0);
    endItFunJUnitXml();
    endDescribeFunJUnitXml();
    startDescribeFunJUnitXml("descr2");
    startItFunJUnitXml("it2-1");
    evalFunJUnitXml("fname", 21, "assertion3", 1);
    pendingFunJUnitXml("reason");
    endItFunJUnitXml();
    endDescribeFunJUnitXml();
    CSpec_JUnitXmlFileClose();

    before(fname);
    IT("output header") {
        check("<?xml version=\"1.0\" encoding=\"shift-jis\" ?>\n");
    } END_IT;
    IT("output testsuites start tag") {
        check("<testsuites>\n");
    } END_IT;
    IT("output testsuite start tag with error=0, failure=1, tests=2") {
        check("  <testsuite errors=\"0\" failures=\"1\" name=\"descr1\" tests=\"2\">\n");
    } END_IT;
    IT("output testcase with assertion=1") {
        check("    <testcase name=\"it1-1\" assertions=\"1\">\n");
        check("    </testcase>\n");
    } END_IT;
    IT("output testcase with assertion=1, failure=1") {
        check("    <testcase name=\"it1-2\" assertions=\"1\">\n");
        check("      <failure message=\"Failed\" type=\"\">\n");
        check("fname:12: assertion2\n");
        check("      </failure>\n");
        check("    </testcase>\n");
    } END_IT;
    IT("output testsuite end tag") {
        check("  </testsuite>\n");
    } END_IT;
    IT("output testsuite start tag with error=0, failure=0, tests=1") {
        check("  <testsuite errors=\"0\" failures=\"0\" name=\"descr2\" tests=\"1\">\n");
    } END_IT;
    IT("output testcase with assertion=0") {
        check("    <testcase name=\"it2-1\" assertions=\"0\">\n");
        check("    </testcase>\n");
    } END_IT;
    IT("output testsuite end tag") {
        check("  </testsuite>\n");
    } END_IT;
    IT("output testsuites end tag") {
        check("</testsuites>\n");
    } END_IT;
    after();
} END_DESCRIBE;

DESCRIBE(destruct_it, "void destruct_it(itOutputs_t* const it)") {
    IT("do nothing when 'it' is null") {
        destruct_it(NULL);
        SHOULD_BE_TRUE(1);
    } END_IT;

    IT("free 'it->failures'") {
        itOutputs_t it;

        it.failures = array_new(1);
        if (NULL == it.failures) {
            SHOULD_PENDING("array_new failed");
        }
        destruct_it(&it);
        SHOULD_BE_NULL(it.failures);
    } END_IT;
} END_DESCRIBE;

DESCRIBE(destruct_descr, "void destruct_descr(descrOutputs_t* const descr)") {
    IT("do nothing when 'descr' is null") {
        destruct_descr(NULL);
        SHOULD_BE_TRUE(1);
    } END_IT;

    IT("free 'descr->it'") {
        descrOutputs_t descr;

        descr.itOutputs = malloc(sizeof(itOutputs_t));
        if (NULL == descr.itOutputs) {
            SHOULD_PENDING("malloc failed");
        }
        descr.n_itOutputs = 1;
        descr.itOutputs[0].failures = array_new(1);
        if (NULL == descr.itOutputs[0].failures) {
            SHOULD_PENDING("array_new failed");
        }
        destruct_descr(&descr);
        SHOULD_BE_NULL(descr.itOutputs);
    } END_IT;
} END_DESCRIBE;
