/* This sample file will describe the 2 following functions:
 *  . fabs
 *  . strcmp
 * Using spanish extensions to do it.
 */

#include <stdio.h>
#include <string.h>

#include "cspec_spanish.h"
#include "cspec_output_header.h"
#include "cspec_output_verbose.h"
#include "cspec_output_unit.h"


/* Here is the description of strcmp */
DESCRIBIR(strcmp, "int strcmp ( const char * str1, const char * str2 )")

	ESCENARIO( "Devuelve 0 solo cuando las cadenas son iguales." )
		DEBE_SER_IGUAL( strcmp("hello", "hello"), 0)
		NO_DEBE_SER_NULL( strcmp("hello", "world") )
	FIN_ESCENARIO

	ESCENARIO( "Devuelve un entero negativo cuando str1 es menor que str2." )
		DEBE_SER_VERDADERO( strcmp("hello", "world") < 0 )
		DEBE_SER_VERDADERO( strcmp("0123", "1321431") < 0 )
	FIN_ESCENARIO

	ESCENARIO( "Devuelve un entero positivo cuando str1 es mayor que str2." )
		DEBE_SER_VERDADERO( strcmp("yellow", "world") > 0 )
		DEBE_SER_VERDADERO( strcmp("9", "789") > 0 )
	FIN_ESCENARIO

FIN_DESCRIBIR

/* Here is the declaration of fabs description defined in an other file (fabs_desc.c in this sample)*/
DECLARAR_DESCRIPCION(fabs)

int main()
{
	/* Run strcmp description with the header output => it will only output all the description titles, 
	   whatever the result of the test 
	*/
	CSpec_Run( DESCRIPTION( strcmp ), CSpec_NewOutputHeader() );

	/* Run the description with verbose output => as much information as possible is output:
	 	- descriptions
		- tests
		- tests results
	*/
	CSpec_Run( DESCRIPCION( fabs ), CSpec_NewOutputVerbose() );
	
	return 0;
}

