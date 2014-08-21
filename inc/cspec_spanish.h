/**
 * @file cspec_spanish.h
 * Fichero principal de cabecera, si queremos hacer un desarrollo
 * BDD mas acorde al lenguaje español.
 *
 * @example
 * #include "cspec_spanish.h"
 * 
 * DESCRIBIR( strcmp, "Descripcion de la funcion 'strcmp'." )
 *   ESCENARIO( "Comparar dos cadenas iguales." )
 *     DEBE_SER_IGUAL( strcmp( "a", "a" ), 0 )
 *   FIN_ESCENARIO
 *
 *   ESCENARIO( "Comparar dos cadenas diferentes." )
 *     NO_DEBE_SER_IGUAL( strcmp( "a", "b" ), 0 )
 *   FIN_ESCENARIO
 * FIN_DESCRIBIR
 * 
 */
#ifndef __CSPEC_SPANISH_H__
#define __CSPEC_SPANISH_H__


#include "cspec.h"


//
//  Conjunto de macros de declaraciones y definiciones de bloques.
//


/**
 * Declara la descripcion de un comportamiento.
 * @param foo Normalmente es el nombre de la funcion de la que se declara su
 * comportamiento.
 */
#define DECLARAR_DESCRIPCION(foo)        DEFINE_DESCRIPTION(foo)

/**
 * Expande la invocacion de una descripcion, para que sea mas facil su uso,
 * de acuerdo a las reglas y patrones de nomenclatura de CSPEC.
 * @param foo El nombre de la descripcion a la que se quiere referenciar.
 */
#define DESCRIPCION(foo)                DESCRIPTION(foo)


/**
 * Define el inicio de bloque de una descripcion. Normalmente
 * este bloque esta asociado a una unidad funcional concreta.
 * @param foo Normalmente el nombre de la funcion que se quiere definir
 * su comportamiento.
 * @param caption Descripcion del comportamiento que se va a definir en
 * este bloque.
 */
#define DESCRIBIR(foo,caption)          DESCRIBE(foo,caption)

/**
 * Marca el fin de un bloque de descripcion.
 */
#define FIN_DESCRIBIR                   END_DESCRIBE



/**
 * Marca un inicio de bloque de un comportamiento. Diferentes
 * ejecuciones de la unidad funcional pueden producir el mismo
 * comportamiento. Esta macro marca el inicio de ese bloque
 * de ejecuciones que se agrupan con un mismo comportamiento.
 * @param caption Descripcion del comportamiento que estamos
 * probando en la accion en particular.
 */
#define ESCENARIO(caption)              IT(caption)

/**
 * Marca el final de un bloque de comportamiento de la unidad
 * funcional que estamos probando o diseñando.
 */
#define FIN_ESCENARIO                   END_IT


//
//  Conjunto de macros para ejecutar comportamientos concretos.
//


/** 
 * La expresion (x) debe ser cierta, para que se cumpla el comportamiento.
 * Usada para expresiones con resultado booleano.
 * @param x La expresion que esperamos que tenga un resultado verdadero.
 */
#define DEBE_SER_VERDADERO(x)           SHOULD_BE_TRUE(x)

/** 
 * La expresion (x) debe ser cierta, para que se cumpla el comportamiento. 
 * Es un sinonimo de la macro DEBE_SER_CIERTO. 
 * @param x La expresion que esperamos que tenga un resultado verdadero.
 */
#define NO_DEBE_SER_FALSO(x)            SHOULD_BE_TRUE(x)

/** 
 * La expresion (x) debe ser igual al resultado de la expresion (y) para 
 * que se cumpla el comportamiento. 
 * @param x La expresion que estamos evaluando.
 * @param y El resultado esperado tras evaluar la expresion.
 */
#define DEBE_SER_IGUAL(x,y)             SHOULD_EQUAL(x,y)

/** 
 * La expresion (x) debe ser igual al resultado de la expresion (y) con 
 * un margen de error de (delta). Usada para expresiones con resultados
 * en coma flotante.
 * @param x La expresion que estamos evaluando.
 * @param y El resultado esperado tras evaluar la expresion.
 * @param delta El margen de error entre el resultado obtenido al evaluar
 * la expresion y el resultado esperado.
 */
#define DEBE_SER_IGUAL_DECIMAL(x,y,delta)       SHOULD_EQUAL_DOUBLE(x,y,delta)

/** 
 * La cadena (x) debe ser igual a la cadena (y) para que se cumpla el 
 * comportamiento. 
 * @param x La primera cadena que queremos comparar.
 * @param y La segunda cadena con la que esperamos que coincida (x).
 */
#define DEBE_COINCIDIR(x,y)             SHOULD_MATCH(x,y)

/**
 * La referencia de la expresión (x) debe ser igual a NULL, para que se 
 * cumpla el comportamiento.
 * @param x La referencia que queremos evaluar.
 */
#define DEBE_SER_NULL(x)                SHOULD_BE_NULL(x)



/** 
 * La expresion (x) debe ser falsa, para que se cumpla el comportamiento.
 * Usada para expresiones con resultado booleano.
 * @param x La expresion que esperamos que tenga un resultado falso.
 */
#define DEBE_SER_FALSO(x)               SHOULD_BE_FALSE(x)

/** 
 * La expresion (x) debe ser falsa, para que se cumpla el comportamiento. 
 * Es un sinonimo de la macro NO_DEBE_SER_CIERTO. 
 * @param x La expresion que esperamos que tenga un resultado falso.
 */
#define NO_DEBE_SER_VERDADERO(x)        SHOULD_BE_FALSE(x)

/** 
 * La expresion (x) debe ser distinto al resultado de la expresion (y) para 
 * que se cumpla el comportamiento. 
 * @param x La expresion que estamos evaluando.
 * @param y El resultado no esperado tras evaluar la expresion.
 */
#define NO_DEBE_SER_IGUAL(x,y)          SHOULD_NOT_EQUAL(x,y)

/** 
 * La expresion (x) debe ser distinto al resultado de la expresion (y) con 
 * un margen de error de (delta). Usada para expresiones con resultados
 * en coma flotante.
 * @param x La expresion que estamos evaluando.
 * @param y El resultado no esperado tras evaluar la expresion.
 * @param delta El margen de error entre el resultado obtenido al evaluar
 * la expresion y el resultado no esperado.
 */
#define NO_DEBE_SER_IGUAL_DECIMAL(x,y,delta)    SHOULD_NOT_EQUAL_DOUBLE(x,y,delta)

/** 
 * La cadena (x) debe ser distintca a la cadena (y) para que se cumpla el 
 * comportamiento. 
 * @param x La primera cadena que queremos comparar.
 * @param y La segunda cadena con la que esperamos que no coincida (x).
 */
#define NO_DEBE_COINCIDIR(x,y)          SHOULD_NOT_MATCH(x,y)

/**
 * La referencia de la expresión (x) no debe ser igual a NULL, para que se 
 * cumpla el comportamiento.
 * @param x La referencia que queremos evaluar.
 */
#define NO_DEBE_SER_NULL(x)             SHOULD_NOT_BE_NULL(x)



#define PENDIENTE(reason)               SHOULD_PENDING(reason)


#endif // __CSPEC_SPANISH_H__


