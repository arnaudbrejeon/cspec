#include <math.h>
#include "cspec.h"

DESCRIBE(fabs, "double fabs( double arg )")

	IT( "returns the same number if the input number is positive" )
		SHOULD_EQUAL( fabs(1.0), 1.0)
		SHOULD_EQUAL( fabs(0.0), 0.0)
		SHOULD_EQUAL( fabs(6.7), 6.7)
	END_IT

	IT( "returns the opposite number if the number is negative"  )
		SHOULD_EQUAL( fabs(-1.0), 1.0)
		SHOULD_EQUAL( fabs(-6.7), 6.7)
	END_IT

END_DESCRIBE