#include "stack.h"
#include <stdlib.h>

struct listnode* list_createnode(char value) {
    struct listnode* p;

    p = malloc(sizeof(*p));
    if (p != NULL) {
        p->ch = value;
        p->next = NULL;
    }
    return p;
}

struct listnode* list_addfront(struct listnode* list, char value) {
    struct listnode* newnode;
    newnode = list_createnode(value);

    if (newnode != NULL) {
        newnode->next = list;
        return newnode;
    }
    return list;
}

struct stack* stack_init() {
    struct stack* s = malloc(sizeof(*s));
    if (s != NULL) {
        s->size = 0;
        s->top = NULL;
    }
    return s;
}

void stack_destroy(struct stack* s) {
    while (s->size > 0)
        stack_pop(s);
    free(s);
}

char stack_push(struct stack* s, char value) {
    int res = 0;
    s->top = list_addfront(s->top, value);
    if (s->top == NULL) {
        res = -1;
    }
    s->size++;
    return res;
}

char stack_pop(struct stack* s) {
    struct listnode* next;
    char value;
    if (s->top == NULL) {
        return -1;
    }
    next = s->top->next;
    value = s->top->ch;
    free(s->top);
    s->top = next;
    s->size--;
    return value;
}
