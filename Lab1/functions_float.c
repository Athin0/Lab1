//
// Created by arina on 26.02.2021.
//
#include "functions_float.h"
#include <string.h>
#include "proto.h"
#include <stdio.h>
lin_form *add_float(struct lin_form *x1, struct lin_form *x2){
    // проверка типов
    size_t size = (x2->size < x1->size) ? x2->size : x1->size;
    size_t size_big = (x2->size > x1->size) ? x2->size : x1->size;
    lin_form *LinForm3 = LinForm_new(LinForm_float_proto, size_big);
    LinForm3->size = size_big;
    LinForm3->data = malloc(sizeof (float)*size_big);
    float *mass1 = (float*) x1->data;
    float *mass2 = (float*) x2->data;
    float *mass3 = (float*) malloc(sizeof(float) * size_big);
    size_t i;
    for (i = 0; i < size; i++){
        mass3[i] = mass1[i] + mass2[i];
    }
    for (i; i < size_big; i++) {
        mass3[i] = (x2->size < x1->size) ? mass1[i] : mass2[i];
    }
    memcpy(LinForm3->data, mass3, sizeof(float) * size_big);
    free(mass3);
    return LinForm3;
}
lin_form *sub_float(struct lin_form *x1, struct lin_form *x2){
    /*if (x1->init != x2->init){
        printf ("Type Obj-1 =! Obj-2 ");
        return 1;
    }*/
    size_t size = (x2->size < x1->size) ? x2->size : x1->size;
    size_t size_big = (x2->size > x1->size) ? x2->size : x1->size;
    lin_form *LinForm3 = LinForm_new(LinForm_float_proto, size_big);
    LinForm3->size = size_big;
    LinForm3->data = malloc(sizeof (float)*size_big);
    float *mass1 = (float*) x1->data;
    float *mass2 = (float*) x2->data;
    float *mass3 = (float*) malloc(sizeof(float) * size_big);
    size_t i;
    for (i = 0; i < size; i++){
        mass3[i] = mass1[i] - mass2[i];
    }
    for (i; i < size_big; i++) {
        mass3[i] = (x2->size < x1->size) ? (-1* mass1[i]) : (-1*  mass2[i]);
    }
    memcpy(LinForm3->data, mass3, sizeof(float) * size_big);
    free(mass3);
    return LinForm3;
}

lin_form *scalMult_float(struct lin_form *x1){
    // проверка типов
    float m;
    printf("Умножить на:");
    scanf("%f", &m);
    size_t size =  x1->size;
    lin_form *LinForm3 = LinForm_new(LinForm_float_proto, size);
    LinForm3->size = size;
    float *mass1 = (float*) x1->data;
    float *mass3 = (float*) malloc(sizeof(float) * size);
    size_t i;
    for (i = 0; i < size; i++){
        mass3[i] = mass1[i] * m;
    }
    memcpy(LinForm3->data, mass3, sizeof(float) * size);
    free(mass3);
    return LinForm3;
}

void *decide_float(lin_form *self) {
    size_t size = self->size;
    float decide = (float) 0;
    float *mass = (float*) self->data;
    float *data = (float*) malloc(sizeof(data) * size);
    //printf("-----------------------\n");
    for (size_t i = 0; i < size; i++) {
        printf("Введите элемент %d ->", i);
        scanf("%f", &data[i]);
        data[i]= data[i] * mass[i];
        decide += data[i];

    }
    for (size_t i = 0; i < size-1; i++) {
        printf(" %f *x[%d] +", mass[i],i);
        data[i]= data[i] * mass[i];
    }
    printf(" %f*x[%d] = %f \n", mass[size-1],size-1,  decide);
    printf("-----------------------\n");
    free(data);
}

/*
lin_form *decide_float(lin_form *self) {
    size_t size = self->size;
    float decide = (float) 0;
    lin_form *LinForm = LinForm_new(LinForm_float_proto, size);
    LinForm->size = size;
    float *mass = (float*) self->data;
    float *data = (float*) malloc(sizeof(data) * size);
    printf("-----------------------\n");
    for (size_t i = 0; i < size; i++) {
         printf("Enter element %d ->", i);
         scanf("%f", &data[i]);
         data[i]= data[i] * mass[i];
         decide += data[i];

    }
    for (size_t i = 0; i < size-1; i++) {
        printf(" %f +", data[i]);
        data[i]= data[i] * mass[i];
    }
    printf(" %f = %f ", data[size-1], decide);
    printf("-----------------------\n");
    memcpy(LinForm->data, data, sizeof(float) * size);
    free(data);
    return LinForm;
}
/**/