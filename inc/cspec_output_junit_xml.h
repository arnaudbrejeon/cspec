/*
 *  cspec_output_juni_xml.h   :  Declaration of the junit xml output
 *
 * See copyright notice in cspec.h
 *
 */

#ifndef CSPEC_OUTPUT_JUNIT_XML_H
#define CSPEC_OUTPUT_JUNIT_XML_H

#include "cspec_output.h"


CSpecOutputStruct* CSpec_NewOutputJUnitXml();

void CSpec_JUnitXmlFileOpen(const char *filename, const char *encoding);
void CSpec_JUnitXmlFileClose(void);

#endif

