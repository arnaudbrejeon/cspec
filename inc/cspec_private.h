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


void CSpec_Eval(const char*filename, int line_number, const char*assertion, int assertionResult);
void CSpec_Pending(const char* reason);

#define CSPEC_EVAL(x) 			{ CSpec_Eval(__FILE__, __LINE__, #x, (x)); }
#define CSPEC_PENDING(reason) 	{ CSpec_Pending(reason); }


#endif

