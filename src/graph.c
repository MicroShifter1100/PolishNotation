#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "polish_math.h"
#include "polish_pars.h"
#include "stack.h"

int main() {
  char exp[N] = "x i =";

  fgets(exp, N, stdin);
  pars(exp, N);

  double number[N] = {0}, mass_Y[80] = {0};
  int znak[N] = {0}, bug = 0;

  converter(znak, &bug, exp, number);

  printf("\n%s\n", exp);
  Y_mass_writer(mass_Y, number, znak, &bug);

  output(mass_Y);
  return 0;
}
