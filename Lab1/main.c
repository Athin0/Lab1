//
// Created by arina on 26.02.2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "proto.h"
#include "meny.h"

int main(void)
{
   system("chcp 65001");
    lin_form types[] = {LinForm_int_proto, LinForm_float_proto};
    int type = 0;
    size_t size1=0, size2=0;
    while(1) {
        int  n;
        printf("Выберите тип данных\n");
        printf("Для работы с ЦЕЛЫМИ числами выберите -> 0\n");
        printf("Для работы с ВЕЩЕСТВЕННЫМИ числами выберите -> 1\n");
        printf("Тип:");
        type=0;
        scanf("%d",&type);
        scanf("%*c");
        printf("%d   ---type", type);

        n=Print_MENU();
        if (n == 5) {
            printf("Работа завршена!");
            break;
        }

        size1=4;
        size1= sizeL();
        lin_form *l1 = LinForm_new(types[type], size1);
        l1->get(l1);
        lin_form *l2 = NULL;
        if (n < 3) {
            printf("Размер 2:");
            size2=5;
            //size2= sizeL();
            l2 = LinForm_new(types[type], size2);
            l2->get(l2);
        }
        
        printf("Линейная форма №1--> ");
        l1->print(l1);
        if (n < 3)
        {
            printf("Линейная форма №2--> ");
            l2->print(l2);
        }
        lin_form *l3=NULL;
        switch (n) {
            case 1: l3= l1->add(l1,l2) ; break;   //add
            case 2: l3 = l1->sub(l1,l2); break;   // sub
            case 3: l3 = l1->scalMult(l1); break;    // mult
            case 4: l1->decide(l1); break;            //dec
            default: break;
        }
        if (n<4) {
            printf("Ответ--> ");
            l3->print(l3);
            l3->destroy(l3);
        }
        if(n<3){
            l2->destroy(l2);
        }
        l1->destroy(l1);
        free(l2);
        free(l3);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }

    return 0;
}