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
	if( CSpec_output->startDescribeFun != 0)
	{
		CSpec_output->startDescribeFun(descr);
	}
}

void CSpec_EndDescribe()
{
	if( CSpec_output->endDescribeFun != 0)
	{
		CSpec_output->endDescribeFun();
	}
}

void CSpec_StartIt(const char *descr)
{
	if(CSpec_output->startItFun != 0)
	{
		CSpec_output->startItFun(descr);
	}
}

void CSpec_EndIt()
{
	if(CSpec_output->endItFun != 0)
	{
		CSpec_output->endItFun();
	}
}

void CSpec_Execute(CSpec_Execution exec, const char*filename, int line_number, const char*assertion, int assertionResult)
{
	if(CSPEC_EXEC_EVAL == exec && CSpec_output->evalFun != 0)
	{
		CSpec_output->evalFun(filename, line_number, assertion, assertionResult);
	}

	if(CSPEC_EXEC_NOT_IMPLEMENTED == exec && CSpec_output->notImplFun != 0)
	{
		CSpec_output->notImplFun(filename, line_number);
	}
}

void CSpec_SetOutput(CSpecOutputStruct* output)
{
	CSpec_output = output;
}

