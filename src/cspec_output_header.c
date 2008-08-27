/*
 *  cspec_output_header.c   :  Generate function headers based on the descriptions
 *
 * See copyright notice in cspec.h
 *
 */

#include <stdio.h>
#include "cspec_output_header.h"

static CSpecOutputStruct header;

void startDescribeFunHeader( const char *descr)
{
	printf("/*******************************************************\n");
	printf(" * \n");
	printf(" * %s \n", descr);
	printf(" * \n");
}

void endDescribeFunHeader( )
{
	printf(" * \n");
	printf(" ********************************************************/\n");
	printf("\n\n");
}

void startItFunHeader( const char *descr)
{
	printf(" *\t- %s\n", descr);
}

CSpecOutputStruct* CSpec_NewOutputHeader()
{
	header.startDescribeFun		= startDescribeFunHeader;
	header.endDescribeFun		= endDescribeFunHeader;
	header.startItFun			= startItFunHeader;
	header.endItFun				= 0;
	header.evalFun				= 0;

	return &header;
}

