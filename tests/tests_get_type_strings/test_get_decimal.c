/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_get_decimal.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/05/19 13:03:50 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_tests.h"

////////////////////////////////////////////////////////////////////////////////

static void	pft_get_decimal_call(t_base_and_prefix_fn get_type_string,
					char *expected, ...)
{
	t_options	options;
	va_list	arg_ptr;

	pft_initialize_options(&options);
	va_start(arg_ptr, expected);
	get_type_string(arg_ptr, &options);
	m_safe_string_assert(options.parts.base_str, expected, true);
	pft_free_parts(&options.parts);
	va_end(arg_ptr);
}

Test(pft_get_decimal)
{
	pft_get_decimal_call(pft_get_decimal, "42", 42);
	pft_get_decimal_call(pft_get_decimal, "42", -42);
	pft_get_decimal_call(pft_get_decimal, "2147483648", -2147483648);
}

////////////////////////////////////////////////////////////////////////////////
