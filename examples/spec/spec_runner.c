#include <stdio.h>
#include <string.h>

#include "cspec.h"
#include "cspec_output_junit_xml.h"
#include "cspec_output_verbose.h"

DEFINE_DESCRIPTION(array_new);
DEFINE_DESCRIPTION(array_delete);
DEFINE_DESCRIPTION(array_add);
DEFINE_DESCRIPTION(array_get_element);

DEFINE_DESCRIPTION(CSpec_NewOutputJUnitXml);
DEFINE_DESCRIPTION(cspec_output_junit_xml_case1);
DEFINE_DESCRIPTION(cspec_output_junit_xml_case2);
DEFINE_DESCRIPTION(destruct_it);
DEFINE_DESCRIPTION(destruct_descr);

int main()
{
    int ret = 0;

    CSpec_JUnitXmlFileOpen("result.xml", "utf-8");

    ret += CSpec_Run(DESCRIPTION(array_new), CSpec_NewOutputJUnitXml());
    ret += CSpec_Run(DESCRIPTION(array_delete), CSpec_NewOutputJUnitXml());
    ret += CSpec_Run(DESCRIPTION(array_add), CSpec_NewOutputJUnitXml());
    ret += CSpec_Run(DESCRIPTION(array_get_element), CSpec_NewOutputJUnitXml());

    CSpec_JUnitXmlFileClose();

    ret += CSpec_Run(DESCRIPTION(CSpec_NewOutputJUnitXml), CSpec_NewOutputVerbose());
    ret += CSpec_Run(DESCRIPTION(cspec_output_junit_xml_case1), CSpec_NewOutputVerbose());
    ret += CSpec_Run(DESCRIPTION(cspec_output_junit_xml_case2), CSpec_NewOutputVerbose());
    ret += CSpec_Run(DESCRIPTION(destruct_it), CSpec_NewOutputVerbose());
    ret += CSpec_Run(DESCRIPTION(destruct_descr), CSpec_NewOutputVerbose());

    return ret;
}
