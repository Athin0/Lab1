//
// Created by arina on 26.02.2021.
//
#include "proto.h"
#ifndef DEPO2_FUNCTIONS_INT_H
#define DEPO2_FUNCTIONS_INT_H

lin_form *add_int(struct lin_form *x1, struct lin_form *x2);
lin_form *sub_int(struct lin_form *x1, struct lin_form *x2);
lin_form *scalMult_int(struct lin_form *x1);
void *decide_int(lin_form *self);
#endif //DEPO2_FUNCTIONS_INT_H
