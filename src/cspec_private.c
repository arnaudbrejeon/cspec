/*
 *  cspec_private.c  :   Private functions
 *
 * See copyright notice in cspec.h
 *
 */

#include "cspec_private.h"
#include "cspec_output.h"

static CSpecOutputStruct* CSpec_output = 0;

void CSpec_StartDescribe(const char *descr)
{
	CSpec_output->startDescribeFun(descr);
}

void CSpec_EndDescribe()
{
	CSpec_output->endDescribeFun();
}

void CSpec_StartIt(const char *descr)
{
	CSpec_output->startItFun(descr);
}

void CSpec_EndIt()
{
	CSpec_output->endItFun();
}

void CSpec_Eval(const char*filename, int line_number, const char*assertion, int assertionResult)
{
	CSpec_output->evalFun(filename, line_number, assertion, assertionResult);
}

void CSpec_SetOutput(CSpecOutputStruct* output)
{
	CSpec_output = output;
}