#ifndef __CSPEC_SPANISH_H__
#ifndef __CSPEC_SPANISH_H__

#include "cspec.h"


#define DESCRIBIR      DESCRIBE
#define FIN_DESCRIBIR  END_DESCRIBE


#define DEFINIR_DESCRIPCION     DEFINE_DESCRIPTION
#define DESCRIPCION             DESCRIPTION


#define HACE      IT
#define FIN_HACE  END_IT



#define NO_DEBE_SER_FALSO(x)            SHOULD_BE_TRUE(x)
#define DEBE_SER_CIERTO(x)              SHOULD_BE_TRUE(x)
#define DEBE_SER_IGUAL(x,y)             SHOULD_EQUAL(x,y)
#define DEBE_SER_IGUAL_FLOTANTE(x,y,delta)       SHOULD_EQUAL_DOUBLE(x,y,delta)
#define DEBE_COINCIDIR(x,y)             SHOULD_MATCH(x,y)
#define DEBE_SER_NULL(x)                SHOULD_BE_NULL(x)

#define NO_DEBE_SER_CIERTO(x)           SHOULD_BE_FALSE(x)
#define DEBE_SER_FALSO(x)               SHOULD_BE_FALSE(x)
#define NO_DEBE_SER_IGUAL(x,y)          SHOULD_NOT_EQUAL(x,y)
#define NO_DEBE_SER_IGUAL_FLOTANTE(x,y,delta)    SHOULD_NOT_EQUAL_DOUBLE(x,y,delta)
#define NO_DEBE_COINCIDIR(x,y)          SHOULD_NOT_MATCH(x,y)
#define NO_DEBE_SER_NULL(x)             SHOULD_NOT_BE_NULL(x)


#endif // __CSPEC_SPANISH_H__


