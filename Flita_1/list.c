//list.c
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#define EXIST true
#define DOES_NOT_EXIST false
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>
// Проверка на существование элемента
bool find(tNode *begin, const char *value) {
    tNode *current = begin;
    while (current != NULL) {
        if (strcmp(current->value, value) == 0) {
            return EXIST;
        }
        current = current->next;
    }
    return DOES_NOT_EXIST;
}

// Добавление нового элемента в список
tNode *push(tNode *begin, const char *value) {
    if (!find(begin, value)) {
        tNode *tmp = (tNode *) malloc(sizeof(tNode));  // Выделяем память для элемента списка
        if (tmp == NULL) { // Проверка ошибки выделения памяти
            fprintf(stderr, "Error: memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        tmp->value = value;  // Задаём значение элемента списка
        tmp->next = begin;  // Передаём значение указателя на предыдущий узел
        return tmp;  // Теперь указатель на начало списка указывает на только что созданный узел
    }
    return begin;
}
void reveal(tNode *begin) {

    while (begin != NULL) {
        puts(begin->value);
        begin = begin->next;
    }
}

// Удаление элемента множества (по значению)
tNode *pop(tNode *begin, const char *value) {
    tNode *prev = NULL;
    tNode *current = begin;
    while (current != NULL) {
        if (strcmp(current->value, value) == 0) {
            if (current == begin) {
                begin = current->next;
                free(current);
            } else {
                prev->next = current->next;
                free(current);
            }
            return begin;
        }
        prev = current;
        current = current->next;
    }
    return begin;
}