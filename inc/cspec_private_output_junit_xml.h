#ifndef CSPEC_PRIVATE_OUTPUT_XML_H
#define CSPEC_PRIVATE_OUTPUT_XML_H

#include "array.h"

typedef struct {
    const char* message;
    const char* type;
    const char* fname;
    int line;
    const char* assertion_descr;
} failure_t;

typedef struct {
    int n_assert;
    int n_pending;
    const char* descr;
    array_t* failures;
} itOutputs_t;

typedef struct {
    const char* descr;
    int n_itOutputs;
    itOutputs_t* itOutputs;
} descrOutputs_t;

#define N_DESCRIBE 10
#define N_IT 10

/* private functions */
void output_header(const char *encoding);
void output_footer();
void output_describe_header(int i);
void output_it(int i, int j);
void output_describe_footer();

#endif
