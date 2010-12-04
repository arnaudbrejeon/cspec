#include <assert.h>
#include <stdlib.h>
#include "array.h"
#include "cspec.h"

DESCRIBE(array_new, "array_t* array_new(size_t element_size)") {
    IT("returns not-NULL pointer") {
        array_t* array = array_new(1);
        SHOULD_NOT_BE_NULL(array);
        array_delete(&array);
    } END_IT;

    IT("returns initialized struct") {
        array_t* array = array_new(2);
        SHOULD_EQUAL(array->element_size, 2);
        SHOULD_EQUAL(array->size, 0);
        SHOULD_EQUAL(array->capacity, 0);
        SHOULD_BE_NULL(array->data);
        array_delete(&array);
    } END_IT;

    IT("returns NULL if element size is 0") {
        SHOULD_BE_NULL(array_new(0));
    } END_IT;
} END_DESCRIBE;

DESCRIBE(array_delete, "void array_delete(array_t** const array)") {
    IT("destruct struct") {
        array_t* array = array_new(1);
        array->size = 1;
        array->capacity = 10;
        array->data = malloc(array->capacity);
        if (NULL == array->data) {
            exit(1);
        }
        array_delete(&array);
        SHOULD_BE_NULL(array);
    } END_IT;

    IT("do nothing if pointer is NULL") {
        array_delete(NULL);
        SHOULD_BE_TRUE(1);
    } END_IT;

    IT("do nothing if *array is NULL") {
        array_t* array = NULL;
        array_delete(&array);
        SHOULD_BE_NULL(array);
    } END_IT;
} END_DESCRIBE;

DESCRIBE(array_add, "int array_add(array_t* const array, const void* const data)") {
    IT("add an element into the array") {
        int data;
        array_t* array;
        int ret;

        array = array_new(sizeof(int));
        assert(NULL != array);

        data = 2;
        ret = array_add(array, &data);
        SHOULD_EQUAL(ret, 0);
        SHOULD_EQUAL(array->size, 1);
        SHOULD_BE_TRUE(1 * sizeof(int) <= array->capacity);
        SHOULD_NOT_BE_NULL(array->data);
        SHOULD_EQUAL(*((int*) array_get_element(array, 0)), 2);
        SHOULD_BE_NULL(array_get_element(array, 1));

        data = -1;
        ret = array_add(array, &data);
        SHOULD_EQUAL(ret, 0);
        SHOULD_EQUAL(array->size, 2);
        SHOULD_BE_TRUE(2 * sizeof(int) <= array->capacity);

        array_delete(&array);
    } END_IT;

    IT("returns 1 if either pointer is NULL") {
        short data;
        array_t array;
        int ret = array_add(NULL, &data);
        SHOULD_EQUAL(ret, 1);
        ret = array_add(&array, NULL);
        SHOULD_EQUAL(ret, 1);
    } END_IT;
} END_DESCRIBE;

DESCRIBE(array_get_element, "void* array_get_element(array_t* const array, size_t idx)") {
    IT("return NULL if idx is over bound") {
        array_t* array = array_new(sizeof(int));
        SHOULD_BE_NULL(array_get_element(array, 1));
        array_delete(&array);
    } END_IT;

    IT("return NULL if pointer is NULL") {
        SHOULD_BE_NULL(array_get_element(NULL, 0));
    } END_IT;
} END_DESCRIBE;
