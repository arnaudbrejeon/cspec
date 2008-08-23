/*
 *  cspec_config.c   :  This file depends on the capabilities of your hardware/platform
 */

// TODO: create CSpecDouble instead of double in case it does not exist

#include <string.h>
#include <math.h>

#include "cspec_config.h"

int cspec_strcmp ( const char * str1, const char * str2 )
{
	return strcmp(str1, str2);
}

cspec_double cspec_fabs( cspec_double arg )
{
	return fabs(arg);
}