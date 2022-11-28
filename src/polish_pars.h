#ifndef SRC_POLISH_PARS_H_
#define SRC_POLISH_PARS_H_
int is_digit(const char ch);
int is_arg(const char ch);
int is_dot(const char ch);
int is_plus(const char ch);
int is_mul(const char ch);
int is_div(const char ch);
int is_minus(const char ch);
int is_cos(const char ch1, const char ch2, const char ch3);
int is_sin(const char ch1, const char ch2, const char ch3);
int is_tan(const char ch1, const char ch2, const char ch3);
int is_ctg(const char ch1, const char ch2, const char ch3);
int is_ln(const char ch1, const char ch2);
int is_sqrt(const char ch1, const char ch2, const char ch3, const char ch4);
int is_opening_bracket(const char ch1);
int is_closing_bracket(const char ch1);
int priority(char op);
int is_end(const char ch);
void pars(char exp[], int n);
#endif  //  SRC_POLISH_PARS_H_
