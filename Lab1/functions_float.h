//
// Created by arina on 26.02.2021.
//
#include "proto.h"
#ifndef DEPO2_FUNCTIONS_FLOAT_H
#define DEPO2_FUNCTIONS_FLOAT_H

lin_form *add_float(struct lin_form *x1, struct lin_form *x2);
lin_form *sub_float(struct lin_form *x1, struct lin_form *x2);
lin_form *scalMult_float(struct lin_form *x1);
void *decide_float(lin_form *self);
#endif //DEPO2_FUNCTIONS_FLOAT_HH

