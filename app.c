#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "array.h"

int main() {
    setlocale(LC_CTYPE, "RUS");

    puts("Лабораторные работы 11, 14, 16\n");
    puts("\n");

    int size;
    printf("Введите количество элементов массива: ");
    scanf("%d", &size);
    puts("\n");

    printf("РАБОТА 11\n");
    task11();
    puts("\n");

    printf("РАБОТА 14\n");
    task14(size);
    puts("\n");

    printf("РАБОТА 16\n");
    task16(size);

    return 0;
}
