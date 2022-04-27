/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_pft_parse_field_width.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/07 15:49:35 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(pft_parse_field_width)
{
	{
		char *format = "42d";
		t_options	options;

		pft_initialize_options(&options);
		pft_parse_field_width(&format, &options.field_width);

		massert(options.field_width, (size_t)42);
		massert(*format, (char)'d');
	}

	{
		char *format = "d";
		t_options	options;

		pft_initialize_options(&options);
		pft_parse_field_width(&format, &options.field_width);

		massert(options.field_width, (size_t)0);
		massert(*format, (char)'d');
	}
}

////////////////////////////////////////////////////////////////////////////////
