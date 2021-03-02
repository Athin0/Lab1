//
// Created by arina on 28.02.2021.
//

#include "meny.h"
#include <stdio.h>

int Print_MENU(void) {
    int n;

    printf("\nМЕНЮ\n");
    printf("1.Сложение\n");
    printf("2.Вычитание\n");
    printf("3.Скалярное произведение\n");
    printf("4.Решить при введенных значениях\n");
    printf("5.Завершить работу\n");
    printf("Введите действие:");

    scanf("%d", &n);
    printf("\n");
    if (n > 5 || n < 1) {
        printf("Неправильно введено число, повторите попытку: ");
        scanf("%d", &n);
        printf("\n");
    }
    return n;
}

int sizeL(void) {
    int n;
    printf("Размер:");
    scanf("%zu ", &n);
    printf("\n");
    return n;

}