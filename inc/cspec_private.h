/*
 *  cspec_private.h
 *
 * See copyright notice in cspec.h
 *
 */
#ifndef CSPEC_PRIVATE_H
#define CSPEC_PRIVATE_H

void CSpec_StartDescribe(const char *descr);
void CSpec_EndDescribe();

void CSpec_StartIt(const char *descr);
void CSpec_EndIt();

typedef enum
{
	CSPEC_EXEC_EVAL,
	CSPEC_EXEC_NOT_IMPLEMENTED
} CSpec_Execution;


void CSpec_Execute(CSpec_Execution exec, const char*filename, int line_number, const char*assertion, int assertionResult);

#define CSPEC_EVAL(x) 			{ CSpec_Execute(CSPEC_EXEC_EVAL, __FILE__, __LINE__, #x, (x)); }
#define CSPEC_NOT_IMPLEMENTED 	{ CSpec_Execute(CSPEC_EXEC_NOT_IMPLEMENTED, __FILE__, __LINE__, "", 0); }


#endif

