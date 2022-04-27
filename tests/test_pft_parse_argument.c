/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_pft_parse_argument.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 16:41:48 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/07 15:49:35 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_tests.h"

////////////////////////////////////////////////////////////////////////////////

void	foo(char *prefix, char *expected, char *format, ...)
{
	t_options	options;
	va_list		arg_ptr;

	pft_initialize_options(&options);
	pft_parse_options_type(&format, &options.type);
	pft_fix_priorities(&options);

	va_start(arg_ptr, format);
	pft_parse_argument(&options, arg_ptr);
	va_end(arg_ptr);

	massert(options.parts.base_str, expected);
	massert(options.parts.prefix, prefix);

	pft_free_parts(&options.parts);
}

Test(pft_parse_argument)
{
	foo("", "a", "c", 'a');
	foo("", "42", "d", 42);
	foo("-", "42", "d", -42);
	foo("-", "2147483648", "d", -2147483648);
	foo("", "42a", "x", 0x42a);
	foo("", "42A", "X", 0x42a);
	foo("", "%", "%");
	foo("0x", "42a", "p", (void *)0x42a);
	foo("", "foo", "s", "foo\0bar");
	foo("", "42", "u", 42);
}

////////////////////////////////////////////////////////////////////////////////
