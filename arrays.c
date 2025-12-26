#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "array.h"

//Task 11 
int task11() {
    float A[N];
    float B[N];

    printf("Заполнение массива из %d элементов:\n", N);
    for (int i = 0; i < N; i++) {
        printf("A[%d] = ", i + 1);
        scanf("%f", &A[i]);
        B[i] = A[i];
    }

    float sum = 0;
    for (int i = 0; i < N; i++) {
        sum += B[i];
    }
    float average = sum / N;
    printf("\nСреднее арифметическое исходных значений: %.4f\n", average);

    for (int i = 0; i < N; i++) {
        A[i] = A[i] * A[i];
    }

    printf("\n| Элемент | Исходный    | После преобразования |\n");
    printf("|---------|-------------|----------------------|\n");

    for (int i = 0; i < N; i++) {
        printf("| A[%2d]   | %11.4f | %20.4f |\n",
            i + 1, B[i], A[i]);
    }

    int first_positive = -1;
    int last_positive = -1;

    for (int i = 0; i < N; i++) {
        if (B[i] > 0) {
            first_positive = i;
            break;
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        if (B[i] > 0) {
            last_positive = i;
            break;
        }
    }

    printf("\nДомашнее задание:\n");
    if (first_positive == -1 || last_positive == -1) {
        printf("В массиве нет положительных элементов\n");
    }
    else if (first_positive == last_positive) {
        printf("В массиве только один положительный элемент: A[%d] = %.4f\n",
            first_positive + 1, B[first_positive]);
    }
    else {
        float sum_between = 0;
        for (int i = first_positive + 1; i < last_positive; i++) {
            sum_between = sum_between + B[i];
        }
        printf("Первый положительный элемент: A[%d] = %.4f\n",
            first_positive + 1, B[first_positive]);
        printf("Последний положительный элемент: A[%d] = %.4f\n",
            last_positive + 1, B[last_positive]);
        printf("Сумма элементов между ними: %.4f\n", sum_between);
    }

    return 0;
}

//Task 14
int task14(int size) {
    double* array;
    array = (double*)malloc(size * sizeof(double));
    if (array == NULL) {
        puts("error");
        return -1;
    }

    double x;
    printf("Введите значения аргумента функции: ");
    scanf("%lf", &x);
    full_elements(array, size, x);
    puts("\n");

    printf("Печать элементов массива:\n");
    put_elements(array, size);
    puts("\n");

    array = calc_elements(array, size);
    printf("Печать элементов преобразованного массива:\n");
    put_elements(array, size);
    puts("\n");

    int begin, end;
    printf("Введите начальный и конечный элементы для суммы: ");
    scanf("%d %d", &begin, &end);
    double sum_result = sum_elements(array, begin - 1, end - 1);
    printf("Сумма: %.2lf\n", sum_result);
    puts("\n");

    double el;
    printf("Введите элемент для поиска: ");
    scanf("%lf", &el);
    int found_index = find_element(array, size, el);
    if (found_index != -1) {
        printf("Найден элемент A[%d] = %.2lf\n", found_index + 1, el);
    }
    else {
        printf("Элемент не найден\n");
    }
    puts("\n");

    int k;
    printf("Введите позицию k: ");
    scanf("%d", &k);
    if (k >= 1 && k <= size) {
        double max_val = array[0];
        for (int i = 1; i < k; i++) {
            if (array[i] > max_val) {
                max_val = array[i];
            }
        }
        printf("Максимум до позиции %d: %.4f\n", k, max_val);
    }
    puts("\n");

    int min_index = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] < array[min_index]) {
            min_index = i;
        }
    }
    printf("Минимальный элемент: A[%d] = %.4f\n", min_index + 1, array[min_index]);

    free(array);
    return 0;
}

// Task 16
int task16(int size) {
    double* array;
    array = (double*)malloc(size * sizeof(double));
    if (array == NULL) {
        puts("error");
        return -1;
    }
    double x;
    printf("Введите значения аргумента функции: ");
    scanf("%lf", &x);
    full_elements(array, size, x);
    puts("\n");

    printf("Печать элементов массива:\n");
    put_elements(array, size);
    puts("\n");

    array = calc_elements(array, size);
    printf("Печать элементов преобразованного массива:\n");
    put_elements(array, size);
    puts("\n");

    int delete_pos;
    printf("Введите номер элемента для удаления (от 1 до %d): ", size);
    scanf("%d", &delete_pos);

    if (delete_pos < 1 || delete_pos > size) {
        printf("Ошибка: номер элемента должен быть от 1 до %d\n", size);
    }
    else {
        int new_size = size - 1;

        if (new_size <= 0) {
            printf("После удаления элемента массив будет пустым\n");
        }
        else {
            double* newarray = (double*)malloc(new_size * sizeof(double));
            if (newarray == NULL) {
                puts("error");
                free(array);
                return -1;
            }

            for (int i = 0; i < delete_pos - 1; i++) {
                newarray[i] = array[i];
            }

            for (int i = delete_pos; i < size; i++) {
                newarray[i - 1] = array[i];
            }

            printf("Массив после удаления элемента A[%d]:\n", delete_pos);
            for (int i = 0; i < new_size; i++) {
                printf("array[%d] = %.4f\n", i + 1, newarray[i]);
            }
            puts("\n");
            free(newarray);
        }
    }

    free(array);
    return 0;
}

// =============== ФУНКЦИИ ===============
double* full_elements(double* ptr_array, int n, double x) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] = calc(x);
        x += 1.0;
    }
    return ptr_array;
}

int put_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        printf("array[%d] = %.4f\n", i + 1, ptr_array[i]);
    }
    return n;
}

double* calc_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] = ptr_array[i] * 2;
    }
    return ptr_array;
}

double calc(double x) {
    return pow(x, 3) - 4 * pow(x, 2) + 2;
}

double sum_elements(double* ptr_array, int begin, int end) {
    if (begin < 0, end < 0, begin > end) {
        return 0.0;
    }

    double sum = 0.0;
    for (int i = begin; i <= end; i++) {
        sum += ptr_array[i];
    }
    return sum;
}

int find_element(double* ptr_array, int n, double element) {
    for (int i = 0; i < n; i++) {
        if (fabs(ptr_array[i] - element) < 0.0001) {
            return i;
        }
    }
    return -1;
}