#ifndef SRC_POLISH_MATH_H_
#define SRC_POLISH_MATH_H_
#define N 100
void converter(int *znak, int *bug, char *mass, double *number);
double Y_calculation(const double *number_osn, const int *znak_osn, int *bug, double x);
void Y_mass_writer(double *mass_Y, double *number, int *znak, int *bug);
void output(double *mass_Y);
#endif  //  SRC_POLISH_MATH_H_
