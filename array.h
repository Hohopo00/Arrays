#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <math.h>

#define N 10

/**
 * Заполняет массив значениями функции x^3 - 4x^2 + 2
 * @param ptr_array указатель на массив
 * @param n количество элементов
 * @param x начальное значение аргумента
 * @return указатель на заполненный массив
 */
double* full_elements(double* ptr_array, int n, double x);

/**
 * Выводит элементы массива на экран
 * @param ptr_array указатель на массив
 * @param n количество элементов
 * @return количество выведенных элементов
 */
int put_elements(double* ptr_array, int n);

/**
 * Удваивает каждый элемент массива
 * @param ptr_array указатель на массив
 * @param n количество элементов
 * @return указатель на преобразованный массив
 */
double* calc_elements(double* ptr_array, int n);

/**
 * Вычисляет значение функции x^3 - 4x^2 + 2 для заданного x
 * @param x аргумент функции
 * @return значение функции
 */
double calc(double x);

/**
 * Вычисляет сумму элементов массива в заданном диапазоне
 * @param ptr_array указатель на массив
 * @param begin начальный индекс (включительно)
 * @param end конечный индекс (включительно)
 * @return сумма элементов
 */
double sum_elements(double* ptr_array, int begin, int end);

/**
 * Ищет элемент в массиве
 * @param ptr_array указатель на массив
 * @param n количество элементов
 * @param element искомое значение
 * @return индекс найденного элемента или -1 если не найден
 */
int find_element(double* ptr_array, int n, double element);

/**
 * Задание 11: Работа с массивом (возведение в квадрат и сумма между положительными)
 * @return 0 при успешном выполнении
 */
int task11();

/**
 * Задание 14: Работа с динамическим массивом (функции, поиск, сумма, минимум)
 * @param size размер массива
 * @return 0 при успешном выполнении, -1 при ошибке
 */
int task14(int size);

/**
 * Задание 16: Операции с массивом (удаление элементов)
 * @param size размер массива
 * @return 0 при успешном выполнении, -1 при ошибке
 */
int task16(int size);

#endif
