#pragma once
struct listnode {
    char ch;
    struct listnode* next;
};

struct stack {
    struct listnode* top;
    int size;
};

struct stack* stack_init();
char stack_push(struct stack* stack, char value);
char stack_pop(struct stack* s);
void stack_destroy(struct stack* s);
struct listnode* list_addfront(struct listnode* list, char value);
struct listnode* list_createnode(char value);
