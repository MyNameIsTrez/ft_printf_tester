/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_get_type_string.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 12:44:11 by sbos          #+#    #+#                 */
/*   Updated: 2022/05/06 15:31:26 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_tests.h"

////////////////////////////////////////////////////////////////////////////////

void	test_get_type_string(t_base_and_prefix_fn get_type_string,
								char *prefix, char *expected, ...)
{
	t_options	options;
	va_list		arg_ptr;

	pft_initialize_options(&options);
	va_start(arg_ptr, expected);
	if (get_type_string(arg_ptr, &options) != SUCCESS)
	{
		pft_free_parts(&options.parts);
		options.parts.base_str = NULL;
	}
	m_safe_string_assert(options.parts.base_str, expected, false);
	m_safe_string_assert(options.parts.prefix, prefix, true);
	pft_free_parts(&options.parts);
	va_end(arg_ptr);
}

////////////////////////////////////////////////////////////////////////////////
