/*
 *  cspec_runner.c   :  ???
 */

#include "cspec.h"

void CSpec_Run( CSpecDescriptionFun fun, CSpecOutputStruct* output )
{
	CSpec_SetOutput(output);
	fun();
}