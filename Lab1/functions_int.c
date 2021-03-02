//
// Created by arina on 26.02.2021.
//
#include "functions_int.h"
#include <string.h>
#include "proto.h"
#include <stdio.h>
lin_form *add_int(struct lin_form *x1, struct lin_form *x2){
    size_t size = (x2->size < x1->size) ? x2->size : x1->size;
    size_t size_big = (x2->size > x1->size) ? x2->size : x1->size;
    lin_form *LinForm3 = LinForm_new(LinForm_int_proto, size_big);
    LinForm3->size = size_big;
    LinForm3->data = malloc(sizeof (int)*size_big);
    int *mass1 = (int*) x1->data;
    int *mass2 = (int*) x2->data;
    int *mass3 = (int*) malloc(sizeof(int) * size_big);
    size_t i;
    for (i = 0; i < size; i++){
        mass3[i] = mass1[i] + mass2[i];
    }
    for (i; i < size_big; i++) {
        mass3[i] = (x2->size < x1->size) ? mass1[i] : mass2[i];
    }
    memcpy(LinForm3->data, mass3, sizeof(int) * size_big);
    free(mass3);
    return LinForm3;
}
lin_form *sub_int(struct lin_form *x1, struct lin_form *x2){
    size_t size = (x2->size < x1->size) ? x2->size : x1->size;
    size_t size_big = (x2->size > x1->size) ? x2->size : x1->size;
    lin_form *LinForm3 = LinForm_new(LinForm_int_proto, size_big);
    LinForm3->size = size_big;
    LinForm3->data = malloc(sizeof (int)*size_big);
    int *mass1 = (int*) x1->data;
    int *mass2 = (int*) x2->data;
    int *mass3 = (int*) malloc(sizeof(int) * size_big);
    size_t i;
    for (i = 0; i < size; i++){
        mass3[i] = mass1[i] - mass2[i];
    }
    for (i; i < size_big; i++) {
        mass3[i] = (x2->size < x1->size) ? (-1* mass1[i]) : (-1*  mass2[i]);
    }
    memcpy(LinForm3->data, mass3, sizeof(int) * size_big);
    free(mass3);
    return LinForm3;
}
lin_form *scalMult_int(struct lin_form *x1){
    size_t size =  x1->size;
    int m;
    scanf("%d", &m);
    lin_form *LinForm3 = LinForm_new(LinForm_int_proto, size);
    LinForm3->size = size;
    LinForm3->data = malloc(sizeof (int)*size);
    int *mass1 = (int*) x1->data;
    int *mass3 = (int*) malloc(sizeof(int) * size);
    size_t i;
    for (i = 0; i < size; i++){
        mass3[i] = mass1[i] * m;
    }
    memcpy(LinForm3->data, mass3, sizeof(int) * size);
    free(mass3);
    return LinForm3;
}


void *decide_int(lin_form *self) {
    size_t size = self->size;
    int decide = (int) 0;
    int *mass = (int*) self->data;
    int *data = (int*) malloc(sizeof(data) * size);
    //printf("-----------------------\n");
    for (size_t i = 0; i < size; i++) {
        printf("Введите элемент %d ->", i);
        scanf("%d", &data[i]);
        data[i]= data[i] * mass[i];
        decide += data[i];

    }
    for (size_t i = 0; i < size-1; i++) {
        printf(" %d*x[%d] +", mass[i],i);
        data[i]= data[i] * mass[i];
    }
    printf(" %d*x[%d] = %d ", mass[size-1], size-1, decide);
    printf("-----------------------\n");
    free(data);
}
/**/
/*
lin_form *decide_int(lin_form *self) {
    size_t size = self->size;
    lin_form *LinForm = LinForm_new(LinForm_int_proto, size);
    LinForm->size = size;
    int *mass = (int*) self->data;
    int *data = (int*) malloc(sizeof(data) * size);
    printf("-----------------------\n");
    for (size_t i = 0; i < size; i++) {
        printf("Enter element %d ->", i);
        scanf("%d", &data[i]);
        data[i]= data[i] * mass[i];
    }
    printf("-----------------------\n");
    memcpy(LinForm->data, data, sizeof(int) * size);
    free(data);
    return LinForm;
} */