/* This sample file will describe the 2 following functions:
 *	. fabs
 *  . strcmp
*/

#include <stdio.h>
#include <string.h>

#include "cspec.h"
#include "cspec_output_xml.h"
#include "cspec_output_unit.h"


/* Here is the description of strcmp */
DESCRIBE(strcmp, "int strcmp ( const char * str1, const char * str2 )")

	IT( "returns 0 only when strings are equal" )
		SHOULD_EQUAL( strcmp("hello", "hello"), 0)
		SHOULD_NOT_BE_NULL( strcmp("hello", "world") )
	END_IT

	IT( "returns a negative integer when str1 is less than str2"  )
		SHOULD_BE_TRUE( strcmp("hello", "world") < 0 )
		SHOULD_BE_TRUE( strcmp("0123", "1321431") < 0 )
	END_IT

	IT( "returns a positive integer if str1 is greater than str2"  )
		SHOULD_BE_TRUE( strcmp("yellow", "world") > 0 )
		SHOULD_BE_TRUE( strcmp("9", "789") == 0 )
		SHOULD_PENDING( "some reason." )
	END_IT

END_DESCRIBE

/* Here is the declaration of fabs description defined in an other file (fabs_desc.c in this sample)*/
DEFINE_DESCRIPTION(fabs)

int main()
{
	CSpec_XmlFileOpen("results.xml", "shift_jis");

	CSpec_Run( DESCRIPTION( strcmp ), CSpec_NewOutputXml() );
	CSpec_Run( DESCRIPTION( fabs ), CSpec_NewOutputXml() );

	CSpec_XmlFileClose();

	return 0;
}

