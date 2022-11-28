#include <stdio.h>
#include "stack.h"

int is_digit(const char ch) { int res = 0; if (ch >= '0' && ch <= '9') {res = 1;} else {res = 0;} return res;}

int is_arg(const char ch) { int res; if (ch == 'x') {res = 1;} else {res = 0;} return res;}

int is_dot(const char ch) {int res; if (ch == '.') {res = 1;} else {res = 0;} return res;}

int is_plus(const char ch) {int res; if (ch == '+') {res = 1;} else {res = 0;} return res;}

int is_mul(const char ch) {int res; if (ch == '*') {res = 1;} else {res = 0;} return res;}

int is_div(const char ch) {int res; if (ch == '/') {res = 1;} else {res = 0;} return res;}

int is_minus(const char ch) {int res; if (ch == '-') {res = 1;} else {res = 0;} return res;}

int is_cos(const char ch1, const char ch2, const char ch3) {int res;
  if (ch1 == 'c' && ch2 == 'o' && ch3 == 's') {res = 1;} else {res = 0;} return res;}

int is_sin(const char ch1, const char ch2, const char ch3) {int res;
  if (ch1 == 's' && ch2 == 'i' && ch3 == 'n') {res = 1;} else {res = 0;} return res;}

int is_tan(const char ch1, const char ch2, const char ch3) {int res;
  if (ch1 == 't' && ch2 == 'a' && ch3 == 'n') {res = 1;} else {res = 0;} return res;}

int is_ctg(const char ch1, const char ch2, const char ch3) {int res;
  if (ch1 == 'c' && ch2 == 't' && ch3 == 'g') {res = 1;} else {res = 0;} return res;}

int is_ln(const char ch1, const char ch2) {int res;
  if (ch1 == 'l' && ch2 == 'n') {res = 1;} else {res = 0;} return res;}

int is_sqrt(const char ch1, const char ch2, const char ch3, const char ch4) {int res;
  if (ch1 == 's' && ch2 == 'q' && ch3 == 'r' && ch4 == 't') {res = 1;} else {res = 0;} return res;}

int is_opening_bracket(const char ch1) {int res; if (ch1 == '(') {res = 1;} else {res = 0;} return res;}

int is_closing_bracket(const char ch1) {int res; if (ch1 == ')') {res = 1;} else {res = 0;} return res;}

int priority(char op) {
    int prior = 0; if (op == '*' || op == '/') { prior = 3;
  } else if (op == '+' || op == '-') {prior = 2;
  } else if (op == 'u' || op == 'i' || op == 'o' || op == 'a' || op == 't' || op == 'q' || op == 'n') {
  prior = 4;} else if (op == '(') { prior = 1;}return prior;}

int is_end(const char ch) {int res = 0; if (ch == '=') {res = 1;} else {res = 0;}return res;}


void pars(char exp[], int n) {
  char parsed[100];
  int i, j = 0;
  struct stack *stack1 = stack_init();
  stack_push(stack1, '=');
  for (i = 0; exp[i] != '\0' && exp[i] != '\n'; i++) {
    if (is_digit(exp[i])) {
        if (!(is_digit(exp[i-1]) || is_digit(exp[i+1]) || is_dot(exp[i-1]) || is_dot(exp[i+1]) || j == 0)) {
            parsed[j] = ' ';
            j++;
        }
        parsed[j] = exp[i];
        j++;
    } else if (is_dot(exp[i])) {
        parsed[j] = exp[i];
        j++;
    } else if (is_plus(exp[i])) {
      char op = stack1->top->ch;
      while (priority(op) > 2) {
        parsed[j] = ' ';
        j++;
        parsed[j] = stack1->top->ch;
        j++;
        stack_pop(stack1);
        op = stack1->top->ch;
      }
      stack_push(stack1, '+');
    } else if (is_mul(exp[i])) {
      char op = stack1->top->ch;
      while (priority(op) > 3) {
        parsed[j] = ' ';
        j++;
        parsed[j] = stack1->top->ch;
        j++;
        stack_pop(stack1);
        op = stack1->top->ch;
      }
      stack_push(stack1, '*');
    } else if (is_div(exp[i])) {
      char op = stack1->top->ch;
      while (priority(op) > 3) {
        parsed[j] = ' ';
        j++;
        parsed[j] = stack1->top->ch;
        j++;
        stack_pop(stack1);
        op = stack1->top->ch;
      }
      stack_push(stack1, '/');
    } else if (is_opening_bracket(exp[i])) {
      stack_push(stack1, '(');
    } else if (is_closing_bracket(exp[i])) {
      char op = stack1->top->ch;
      while (priority(op) > 1) {
        parsed[j] = ' ';
        j++;
        parsed[j] = stack1->top->ch;
        j++;
        stack_pop(stack1);
        op = stack1->top->ch;
      }
      if (stack1->top->ch == '(') {
        stack_pop(stack1);
      } else {
        printf("ERRRRORRR!!!!!!");
        exp[i + 1] = '\0';
      }
    } else if (is_end(exp[i])) {
      char op = stack1->top->ch;
      while (priority(op) > 1) {
        parsed[j] = ' ';
        j++;
        parsed[j] = stack1->top->ch;
        j++;
        stack_pop(stack1);
        op = stack1->top->ch;
      }
      parsed[j] = ' ';
      j++;
      parsed[j] = '=';
      j++;
    } else if (is_minus(exp[i])) {
      if (j == 0 || priority(exp[i - 1]) || is_opening_bracket(exp[i + 1]))
        stack_push(stack1, 'u');
      else
        stack_push(stack1, '-');
    } else if (n - i > 3 && is_sin(exp[i], exp[i + 1], exp[i + 2])) {
      stack_push(stack1, 'i');
      i += 2;
    } else if (n - i > 3 && is_cos(exp[i], exp[i + 1], exp[i + 2])) {
      stack_push(stack1, 'o');
      i += 2;
    } else if (n - i > 3 && is_tan(exp[i], exp[i + 1], exp[i + 2])) {
      stack_push(stack1, 'a');
      i += 2;
    } else if (n - i > 3 && is_ctg(exp[i], exp[i + 1], exp[i + 2])) {
      stack_push(stack1, 't');
      i += 2;
    } else if (n - i > 4 &&
               is_sqrt(exp[i], exp[i + 1], exp[i + 2], exp[i + 3])) {
      stack_push(stack1, 'q');
      i += 2;
    } else if (n - i > 2 && is_ln(exp[i], exp[i + 1])) {
      stack_push(stack1, 'n');
      i++;
    } else if (is_arg(exp[i])) {
        if (j != 0) {
            parsed[j] = ' ';
            j++;
        }
        parsed[j] = exp[i];
        j++;
    } else {
      printf("ERROR!");
    }
  }
  parsed[j] = '\0';
  for (int k = 0; k < j; k++) {
    exp[k] = parsed[k];
  }
  exp[j] = '\0';
  stack_destroy(stack1);
}
