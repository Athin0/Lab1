//
// Created by arina on 26.02.2021.
//
#include "proto.h"
#include "functions_int.h"
#include "functions_float.h"
#include <string.h>
#include <stdio.h>

lin_form LinForm_int_proto = {
        .init = LinForm_int_init,
        .destroy = LinForm_int_destroy,
        .print = LinForm_int_print,
        .get = LinForm_int_get,
        .add = add_int,
        .sub= sub_int,
        .scalMult=scalMult_int,
        .decide=decide_int
};

lin_form LinForm_float_proto = {
        .init = LinForm_float_init,
        .destroy = LinForm_float_destroy,
        .print = LinForm_float_print,
        .get = LinForm_float_get,
        .add = add_float,
        .sub = sub_float,
        .scalMult=scalMult_float,
        .decide=decide_float
};


void *LinForm_new(lin_form proto, size_t size) {
    lin_form *el = (lin_form*) malloc(sizeof(lin_form));
    *el = proto;                                           //lin_form LinForm_float_proto
    el->size = size;                                       // LinForm_int_proto
    el->init(el);
    return el;

}
// int
void LinForm_int_get(lin_form *self) {
    size_t size = self->size;
    int *data = (int*) malloc(sizeof(data) * size);
    //printf("-----------------------\n");
    for (size_t i = 0; i < size; i++) {
        printf("Enter element %d ->", i+1);
        scanf("%d", &data[i]);
        //data[i] = rand()%100;

    }
    printf("-----------------------\n");
    memcpy(self->data, data, sizeof(int) * size);
    free(data);
}
void LinForm_int_init(lin_form *self) {
    size_t size = self->size;
    self->data = malloc(sizeof(int) * size);
}

void LinForm_int_destroy(lin_form *self) {
    if ( self ) {
        if ( self->data ) {
            free(self->data);
        }
        free(self);
    }
}

void LinForm_int_print(lin_form *self) {
    size_t size = self->size;
    int *data = (int*)self->data;
    printf("{");
    for (size_t i = 0; i < size; i++) {
        printf(" %d*x[%d] +", data[i],i);
        //printf("%d", data[i]);
        if (i == size - 1)
            printf("}\n");
        else
            printf(", ");
    }
}



// float


void LinForm_float_get(lin_form *self) {
    size_t size = self->size;
    float *data = (float*) malloc(sizeof(data) * size);
    //printf("-----------------------\n");
    for (size_t i = 0; i < size; i++) {
        //printf("Enter element %d ->", i+1);
       //scanf("%f", &data[i]);
        data[i] = ((float) (rand()%100+1) /(float) (rand()%100+1));
    }
    printf("-----------------------\n");
    memcpy(self->data, data, sizeof(float) * size);
    free(data);
}
void LinForm_float_init(lin_form *self) {
    size_t size = self->size;
    self->data = malloc(sizeof(float) * size);
}

void LinForm_float_destroy(lin_form *self) {
    if ( self ) {
        if ( self->data ) {
            free(self->data);
        }
        free(self);
    }
}
void LinForm_float_print(lin_form *self) {
    size_t size = self->size;
    float *data = (float*)self->data;
    printf("{");
    for (size_t i = 0; i < size; i++) {
        //printf(" %f*x[%d] ", data[i],i);
        printf("%f", data[i]);
        if (i == size - 1)
            printf("}\n");
        else
            printf(" + ");
    }
}

