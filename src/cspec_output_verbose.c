/*
 *  cspec_output_verbose.c   :  Verbose output
 *
 * See copyright notice in cspec.h
 *
 */

#include <stdio.h>
#include "cspec_output_verbose.h"

static CSpecOutputStruct verbose;

void startDescribeFunVerbose( const char *descr)
{
	printf("Describe:%s\n", descr);
}

void endDescribeFunVerbose( )
{
	printf("\n");
}

void startItFunVerbose( const char *descr)
{
	printf("   - it %s\n", descr);
}

void endItFunVerbose( )
{
	printf("\n");
}

void evalFunVerbose(const char*filename, int line_number, const char*assertion, int assertionResult)
{
	if(assertionResult)
	{
		printf("       OK: %s\n", assertion, filename, line_number);
	}
	else
	{
		printf("       Failed: %s in file %s at line %d\n", assertion, filename, line_number);
	}
}

CSpecOutputStruct* CSpec_NewOutputVerbose()
{
	verbose.startDescribeFun	= startDescribeFunVerbose;
	verbose.endDescribeFun		= endDescribeFunVerbose;
	verbose.startItFun			= startItFunVerbose;
	verbose.endItFun			= endItFunVerbose;
	verbose.evalFun				= evalFunVerbose;

	return &verbose;
}