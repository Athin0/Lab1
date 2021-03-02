//
// Created by arina on 26.02.2021.
//

#ifndef DEPO2_PROTO_H
#define DEPO2_PROTO_H
#include "stdlib.h"
typedef struct lin_form{
    size_t size;
    void *data;
    void (*init)(struct lin_form *self);                    //creat struct+ its functions
    void (*destroy)(struct lin_form *self);
    void (*print)(struct lin_form *self);
    void (*get)(struct lin_form *self);
    struct lin_form* (*add)(struct lin_form *x1, struct lin_form *x2);
    struct lin_form* (*sub)(struct lin_form *x1, struct lin_form *x2);
    struct lin_form* (*scalMult)(struct lin_form *x1);
    void* (*decide)(struct lin_form *x1);
} lin_form;


lin_form LinForm_int_proto;
lin_form LinForm_float_proto;

void *LinForm_new(lin_form proto, size_t size);

void LinForm_int_init( lin_form *self);
void LinForm_int_destroy(lin_form *self);
void LinForm_int_print(lin_form *self);
void LinForm_int_get(lin_form *self);

void LinForm_float_init(lin_form *self);
void LinForm_float_destroy(lin_form *self);
void LinForm_float_print(lin_form *self);
void LinForm_float_get(lin_form *self);

#endif //DEPO2_PROTO_H
