/*
 *  cspec_output.c   :  
 *
 *
 * See copyright notice in cspec.h
 *
 */

#include "cspec.h"
#include <memory.h>

void CSpec_InitOutput( CSpecOutputStruct* output )
{
	memset(output, 0, sizeof(CSpecOutputStruct) );
}

