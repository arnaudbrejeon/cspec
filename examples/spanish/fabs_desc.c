#include <math.h>
#include "cspec_spanish.h"

DESCRIBIR( fabs, "double fabs( double arg )" )

	ESCENARIO( "Devuelve el mismo numero, si la entrada es positiva." )
		DEBE_SER_IGUAL( fabs(1.0), 1.0 )
		DEBE_SER_IGUAL( fabs(0.0), 0.0 )
		DEBE_SER_IGUAL( fabs(6.7), 6.7 )
	FIN_ESCENARIO

	ESCENARIO( "Devuelve el opuesto, si la entrada es negativa." )
		DEBE_SER_IGUAL( fabs(-1.0), 1.0 )
		DEBE_SER_IGUAL( fabs(-6.7), 6.7 )
	FIN_ESCENARIO

FIN_DESCRIBIR

