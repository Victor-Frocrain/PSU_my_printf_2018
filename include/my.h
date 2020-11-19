/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <SFML/Graphics.h>

#ifndef MY_H_
#define MY_H_
#define MY_EXIT_ERROR (84)
#define MY_EXIT_SUCCESS (0)

struct format_t {
    bool space;
    bool plus;
    bool sharp;
    bool zero;
    bool blank;
};

typedef struct format_t format;
int sum_stdarg(int i, int nb, ...);
int my_printf(char *s, ...);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_show_word_array(char * const *tab);
char **my_str_to_word_array(char const *str);
struct info_param *my_params_to_array(int ac, char **av);
int my_show_param_array(struct info_param const *par);
char *my_strdup(char *str);
int my_put_unsigned_int(unsigned int nb);
char *my_memset(char *str, char c, int size);
int my_intlen(unsigned int nb);
char *convert_dec_to_hexa(unsigned int nb, int casse);
char *convert_dec_to_octal(unsigned int nb, bool nprint);
char *convert_dec_to_binary(unsigned int nb);
void check_case(char c, va_list list);
void my_putstr_non_print(char *str);
void my_putchar_non_print(unsigned int c);
void manage_format(char c, va_list list, format *form);
format *init_format(format *form);
void check_format(char c, format *form);
int manage_zero(char *str, va_list list, format *form, int i);
bool fill_number(char c, int result, format *form, va_list list);
void manage_format(char c, va_list list, format *form);

#endif /* MY_H_ */
