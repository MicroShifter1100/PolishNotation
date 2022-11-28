#include <stdio.h>
#include <math.h>
#include "polish_math.h"

void converter(int *znak, int *bug, char *mass, double *number) {
  int i = 0, k = 0, point = 0;
  double sum = 0.0, a = 10.0;

  while (mass[k] != '=') {
    if (mass[k] == '*' || mass[k] == '/' || mass[k] == '-' || mass[k] == '+')
    {znak[i] = mass[k];}
    if (((mass[k] >= '0' && mass[k] <= '9') && point == 0)) {
      sum = sum * 10 + ((int)mass[k] - 48);}
    if (((mass[k] >= '0' && mass[k] <= '9') && point == 1)) {
      sum = sum + (((int)mass[k] - 48) / a); a *= 10;}
    if (mass[k] == '.')point = 1;
    if (mass[k] >= 'a' && mass[k] <= 'z') {
      switch (mass[k]) {
      case 105: znak[i] = 2; break;
      case 111: znak[i] = 3; break;
      case 97: znak[i] = 4; break;
      case 116: znak[i] = 5; break;
      case 113: znak[i] = 6; break;
      case 110: znak[i] = 7; break;
      case 117: znak[i] = 8; break;
      case 120: znak[i] = 9; break;}}
    if (mass[k - 1] >= '0' && mass[k - 1] <= '9') {
      point = 0; a = 10.0; number[i] = sum; znak[i] = 1; sum = 0;}
    if (znak[i] != 0) {i++;} k++;} znak[i] = mass[k];
  if (znak[0] != 1 || (znak[1] < 1 || znak[1] > 9)) *bug = 2;
}

double Y_calculation(const double *number_osn, const int *znak_osn, int *bug, double x) {
  double number[N] = {0};
  int a = 100;
  int b = 100;
  int j = 0;
  int znak[N] = {0};
  for (int i = 0; i < N; i++) {znak[i] = znak_osn[i]; number[i] = number_osn[i];}
  for (int i = 0; i < N; i++)if (znak[i] == 9) {number[i] = x; znak[i] = 1;}
  while (znak[j - 1] != 61 && *bug < 1) {
    if (znak[j] == 1) {b = a; a = j;}
    if (znak[j] > 1 && znak[j] < 9) {if (znak[a] != 1) {*bug = 3;} else {
        switch (znak[j]) {
        case 2: number[a] = sin(number[a]); break;
        case 3: number[a] = cos(number[a]); break;
        case 4: if ((cos(number[a])) == 0) {*bug = 13; } else {number[a] = tan(number[a]);} break;
        case 5: if ((sin(number[a])) == 0) {*bug = 14;} else {
            number[a] = cos(number[a]) / sin(number[a]);} break;
        case 6: if (number[a] < 0) {*bug = 4;} else {number[a] = sqrt(number[a]);} break;
        case 7: if (number[a] <= 0) {*bug = 5;} else {number[a] = log(number[a]);} break;
        case 8:number[a] = ((number[a]) * (-1)); break;}
        a = 100; b = 100; znak[j] = 0; j = 0; continue; }}

    if (znak[j] > 41 && znak[j] < 48) {
      if (znak[a] != 1 || znak[b] != 1 || a == b) {*bug = 6;} else {
        switch (znak[j]) {
        case 42:number[a] = (number[b] * number[a]); break;
        case 43:number[a] = (number[b] + number[a]); break;
        case 45:number[a] = (number[b] - number[a]); break;
        case 47:if (number[a] == 0) {*bug = 15;} else {number[a] = (number[b] / number[a]);} break;}
        number[b] = 0; znak[b] = 0; znak[j] = 0; a = 100; b = 100; j = 0; continue;}}j++;}
  if (znak[j - 1] == 61) {if (b != 100)*bug = 111;}return number[a];
}

void Y_mass_writer(double *mass_Y, double *number, int *znak, int *bug) {
  for (int i = 0; i < 80; i++) {double x = i * 4.0 * M_PI / 80;
  mass_Y[i] = ((Y_calculation(number, znak, bug, x)) * 4 * M_PI) + 12;}
}

void output(double *mass_Y) {
  int mass_pole[25][80] = {0};
  for (int i = 0; i < 80; i++) {
    if ((int)mass_Y[i] < 25 && (int)mass_Y[i] >= 0) { mass_pole[(int)mass_Y[i]][i] = 1;}}
  for (int y = 0; y < 25; y++) {
    for (int x = 0; x < 80; x++) {
      if (mass_pole[y][x] == 1) {printf("* ");} else {printf(". ");}} printf("\n");}}
