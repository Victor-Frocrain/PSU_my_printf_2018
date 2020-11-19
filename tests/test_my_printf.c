/*
** EPITECH PROJECT, 2018
** test my_printf
** File description:
** test my_printf
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, display_normal, .init = redirect_all_std)
{
    my_printf("%c%s%d", 'A', "Bonjour", 42);
    cr_assert_stdout_eq_str("ABonjour42");
}

Test(my_printf, display_with_invalid1, .init = redirect_all_std)
{
    my_printf("%c%s%da", 'A', "Bonjour", 42);
    cr_assert_stdout_eq_str("ABonjour42a");
}

Test(my_printf, display_with_invalid2, .init = redirect_all_std)
{
    my_printf("%c%sa%d", 'A', "Bonjour", 42);
    cr_assert_stdout_eq_str("ABonjoura42");
}

Test(my_printf, display_without_flag, .init = redirect_all_std)
{
    my_printf("Bonjour comment ca va ?");
    cr_assert_stdout_eq_str("Bonjour comment ca va ?");
}

Test(my_printf, display_modulo, .init = redirect_all_std)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, display_integers_with_different_flags, .init = redirect_all_std)
{
    my_printf("%i %d", 42, 3);
    cr_assert_stdout_eq_str("42 3");
}

Test(my_printf, display_unsignedint, .init = redirect_all_std)
{
    my_printf("%u", 3000000000);
    cr_assert_stdout_eq_str("3000000000");
}

Test(my_printf, display_hexa, .init = redirect_all_std)
{
    my_printf("%x %x", 45, 40000);
    cr_assert_stdout_eq_str("2d 9c40");
}

Test(my_printf, display_octal, .init = redirect_all_std)
{
    my_printf("%o %o", 45, 40000);
    cr_assert_stdout_eq_str("55 116100");
}

Test(my_printf, display_hexa_maj, .init = redirect_all_std)
{
    my_printf("%X %X", 45, 40000);
    cr_assert_stdout_eq_str("2D 9C40");
}

Test(my_printf, display_string_non_printable, .init = redirect_all_std)
{
    my_printf("%S\n", "a\rb");
    cr_assert_stdout_eq_str("a\\015b\n");
}

Test(my_printf, display_binary, .init = redirect_all_std)
{
    my_printf("%b\n", 42);
    cr_assert_stdout_eq_str("101010\n");
}

Test(my_printf, display_hexa_from_int, .init = redirect_all_std)
{
    my_printf("%p\n", 50);
    cr_assert_stdout_eq_str("0x32\n");
}

Test(my_printf, display_hexa_from_char, .init = redirect_all_std)
{
    my_printf("%p\n", 'a');
    cr_assert_stdout_eq_str("0x61\n");
}

Test(my_printf, display_with_space, .init = redirect_all_std)
{
    my_printf("%    d", 70);
    cr_assert_stdout_eq_str(" 70");
}

Test(my_printf, display_with_space_minus, .init = redirect_all_std)
{
    my_printf("% d", -70);
    cr_assert_stdout_eq_str("-70");
}

Test(my_printf, display_with_space_without_flag, .init = redirect_all_std)
{
    my_printf("hello% \n");
    cr_assert_stdout_eq_str("hello% \n");
}

Test(my_printf, display_wide_char, .init = redirect_all_std)
{
    my_printf("%C %C", 127, 'a');
    cr_assert_stdout_eq_str("\\177 a");
}

Test(my_printf, display_integer_and_others, .init = redirect_all_std)
{
    my_printf("% ddac", 24);
    cr_assert_stdout_eq_str(" 24dac");
}

Test(my_printf, display_format_plus, .init = redirect_all_std)
{
    my_printf("%+d", 24);
    cr_assert_stdout_eq_str("+24");
}

Test(my_printf, display_format_plus_space, .init = redirect_all_std)
{
    my_printf("% +d", 24);
    cr_assert_stdout_eq_str("+24");
}

Test(my_printf, false_flag, .init = redirect_all_std)
{
    my_printf("a%");
    cr_assert_stdout_eq_str("a");
}

Test(my_printf, display_flag_sharp, .init = redirect_all_std)
{
    my_printf("%#o", 42);
    cr_assert_stdout_eq_str("052");
}

Test(my_printf, display_multi_flag_sharp, .init = redirect_all_std)
{
    my_printf("%###############################o", 42);
    cr_assert_stdout_eq_str("052");
}

Test(my_printf, display_zero_without_prefix, .init = redirect_all_std)
{
    my_printf("%#o", 0);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf, display_zero_octal, .init = redirect_all_std)
{
    my_printf("%o", 0);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf, display_hexa_with_prefix, .init = redirect_all_std)
{
    my_printf("%###x", 42);
    cr_assert_stdout_eq_str("0x2a");
}

Test(my_printf, display_hexa_maj_with_prefix, .init = redirect_all_std)
{
    my_printf("%###X", 42);
    cr_assert_stdout_eq_str("0X2A");
}

Test(my_printf, display_hexa_zero, .init = redirect_all_std)
{
    my_printf("%x", 0);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf, display_hexa_zero_without_prefix, .init = redirect_all_std)
{
    my_printf("%#x", 0);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf, display_space_plus, .init = redirect_all_std)
{
    my_printf("% +i % +d", 42, 0);
    cr_assert_stdout_eq_str("+42 +0");
}

Test(my_printf, format_zero_normal, .init = redirect_all_std)
{
    my_printf("%04d", 24);
    cr_assert_stdout_eq_str("0024");
}

Test(my_printf, format_zero_double, .init = redirect_all_std)
{
    my_printf("%04d %i", 24, 38);
    cr_assert_stdout_eq_str("0024 38");
}

Test(my_printf, format_zero_blank, .init = redirect_all_std)
{
    my_printf("%06.i", 38);
    cr_assert_stdout_eq_str("    38");
}

Test(my_printf, format_zero2, .init = redirect_all_std)
{
    my_printf("%04i%05.d", 38, 456);
    cr_assert_stdout_eq_str("0038  456");
}

Test(my_printf, format_zero3, .init = redirect_all_std)
{
    my_printf("%04i  %05.d", 38, 456);
    cr_assert_stdout_eq_str("0038    456");
}

Test(my_printf, format_zero_plus, .init = redirect_all_std)
{
    my_printf("%0+4i", 38);
    cr_assert_stdout_eq_str("+038");
}

Test(my_printf, format_zero_empty, .init = redirect_all_std)
{
    my_printf("%0i", 38);
    cr_assert_stdout_eq_str("38");
}

Test(my_printf, format_zero_hexa, .init = redirect_all_std)
{
    my_printf("%04x %03X", 47, 42);
    cr_assert_stdout_eq_str("002f 02A");
}

Test(my_printf, format_zero_hexa_ten, .init = redirect_all_std)
{
    my_printf("%04x %010X", 47, 42);
    cr_assert_stdout_eq_str("002f 000000002A");
}

Test(my_printf, format_double_zero_hexa_ten, .init = redirect_all_std)
{
    my_printf("%004x %0010X", 47, 42);
    cr_assert_stdout_eq_str("002f 000000002A");
}

Test(my_printf, format_zero_octal, .init = redirect_all_std)
{
    my_printf("%007o", 42);
    cr_assert_stdout_eq_str("0000052");
}

Test(my_printf, format_zero_unsigned, .init = redirect_all_std)
{
    my_printf("%007u", 42);
    cr_assert_stdout_eq_str("0000042");
}
