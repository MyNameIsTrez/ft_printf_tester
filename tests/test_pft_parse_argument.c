/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_pft_parse_argument.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 16:41:48 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/29 12:49:36 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_tests.h"

////////////////////////////////////////////////////////////////////////////////

void	pft_parse_argument_call(char *prefix, char *expected, char *format, ...)
{
	t_options	options;
	va_list		arg_ptr;

	pft_initialize_options(&options);
	pft_parse_options_type(&format, &options.type);
	pft_fix_priorities(&options);

	va_start(arg_ptr, format);
	if (pft_parse_argument(&options, arg_ptr) != OK)
	{
		pft_free_parts(&options.parts);
		options.parts.base_str = NULL;
	}
	va_end(arg_ptr);

	m_safe_string_assert(options.parts.base_str, expected, false);
	m_safe_string_assert(options.parts.prefix, prefix, true);

	pft_free_parts(&options.parts);
}

Test(pft_parse_argument)
{
	pft_parse_argument_call("", "a", "c", 'a');
	pft_parse_argument_call("", "42", "d", 42);
	pft_parse_argument_call("-", "42", "d", -42);
	pft_parse_argument_call("-", "2147483648", "d", -2147483648);
	pft_parse_argument_call("", "42a", "x", 0x42a);
	pft_parse_argument_call("", "42A", "X", 0x42a);
	pft_parse_argument_call("", "%", "%");
	pft_parse_argument_call("0x", "42a", "p", (void *)0x42a);
	pft_parse_argument_call("", "foo", "s", "foo\0bar");
	pft_parse_argument_call("", "42", "u", 42);
}

////////////////////////////////////////////////////////////////////////////////
