// list.h
#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct sNode {
    struct sNode *next;
    const char *value;
} tNode;

bool find(tNode *begin, const char *value);
tNode *push(tNode *begin, const char *value);
tNode *pop(tNode *begin, const char *value);
void reveal(tNode *begin);

#endif