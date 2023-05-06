#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "list.c"
#define BASE_STRING_LEN 10

//  Ввод элемента
char *enter() {
    int64_t len = BASE_STRING_LEN;
    char *str = malloc(sizeof(char) * (len + 1));
    char character;
    int64_t str_size = 0;
    for(;(character = getchar()) != '\n' && character != '\r'; str_size++) {
        if (str_size + 1 >= len) {
            len = 2 * str_size + 1;
            str = realloc(str, len);
            if (str == NULL) { // Проверка ошибки выделения памяти
                fprintf(stderr, "Error: memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
        }
        str[str_size] = character;
    }
    char *exit = malloc(sizeof(char) * (str_size + 1));
    for (int64_t i = 0; i < str_size; i++) {
        exit[i] = str[i];
    }
    exit[str_size] = '\0';
    free(str);
    return exit;
}


// Задание множества
tNode* establish(tNode *set) {
    int64_t elements;
    puts("Enter the number of elements:");
    while (scanf("%ld", &elements) != 1 || elements < 0) {
        puts("Invalid input. Please enter a integer type:");
        while (getchar() != '\n'); // Очистка входного потока
    }
    getchar(); // Удаление символа новой строки из входного потока
    for (int64_t i = 0; i < elements; i++) {
        puts("Enter the element:");
        const char *element = enter();
        set = push(set, element);
    }
    return set;
}

// Выбор множества
tNode* operations(tNode *set) {
    puts("Enter:\n1 to add new element\n2 to delete\n3 to show the set\nS to interrupt");
    char opt;
    while ((opt = getchar()) != 'S') {
        fflush(stdin);
        switch (opt) {
            case '1':
                puts("Adding. Enter the element:");
                set = push(set, enter());
                break;
            case '2':
                puts("Deletion. Enter the element:");
                set = pop(set, enter());
                break;
            case '3':
                reveal(set);
                break;
            case 'S':
                puts("Interrupted");
            default:
                puts("Unsupported operation!\n");
        }
        puts("What's next?");
    }
    return set;
}

int64_t main() {
    tNode* set_A = NULL;
    tNode* set_B = NULL;

    puts("Enter the set A");
    set_A = establish(set_A);
    puts("Enter the set B");
    set_B = establish(set_B);

    puts("Choose a set to work with (A or B):");
    char opt;
    while (scanf(" %c", &opt) == 1 && opt != 'Q') {
        switch (opt) {
            case 'A':
                puts("Set A");
                set_A = operations(set_A);
                break;
            case 'B':
                puts("Set B");
                set_B = operations(set_B);
                break;
            case 'Q':
                puts("Quit");
            default:
                puts("Unsupported operation!\n");
        }
        puts("Choose a set to work with (A or B):");
    }

    return 0;
}