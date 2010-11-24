/*
 *  cspec_output_verbose.h   :  Declaration of the verbose output
 *
 * See copyright notice in cspec.h
 *
 */

#ifndef CSPEC_OUTPUT_VERBOSE_H
#define CSPEC_OUTPUT_VERBOSE_H

#include "cspec_output.h"


typedef enum
{
	CSPEC_COLOR_RED = 1,
	CSPEC_COLOR_GREEN = 2,
	CSPEC_COLOR_YELLOW = 3
} CSpec_Color;


CSpecOutputStruct* CSpec_NewOutputVerbose();

#endif

