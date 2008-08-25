/*
 *  cspec_runner.c   :  The runner
 *
 * TODO: What if fun or output of NULL? Should we set the output for each run?
 *
 * See copyright notice in cspec.h
 *
 */

#include "cspec.h"

void CSpec_Run( CSpecDescriptionFun fun, CSpecOutputStruct* output )
{
	CSpec_SetOutput(output);
	fun();
}