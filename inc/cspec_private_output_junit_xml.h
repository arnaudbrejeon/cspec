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
void startDescribeFunJUnitXml(const char *descr);
void endDescribeFunJUnitXml(void);
void startItFunJUnitXml(const char *descr);
void endItFunJUnitXml();
void evalFunJUnitXml(const char *filename, int line_number, const char *assertion, int assertionResult);
void pendingFunJUnitXml(const char* reason);

void output_header(const char *encoding);
void output_footer();
void output_describe();
void output_describe_header(const descrOutputs_t* const descr);
void output_describe_main(const descrOutputs_t* const descr);
void output_describe_footer();
void output_it(const itOutputs_t* const it);
void output_it_header(const itOutputs_t* const it);
void output_it_main(const itOutputs_t* const it);
void output_it_footer();
int sumup_failure(const descrOutputs_t* const p);
void destruct();
void destruct_descr(descrOutputs_t* const descr);
void destruct_it(itOutputs_t* const it);

#endif
