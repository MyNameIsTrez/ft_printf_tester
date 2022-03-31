/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_field_width.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/04 18:53:17 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(parse_field_width)
{
	{
		char *format = "42d";
		t_options	options;

		pft_initialize_options(&options);
		parse_field_width(&format, &options.field_width);

		massert(options.field_width, (size_t)42);
		massert(*format, (char)'d');
	}

	{
		char *format = "d";
		t_options	options;

		pft_initialize_options(&options);
		parse_field_width(&format, &options.field_width);

		massert(options.field_width, (size_t)0);
		massert(*format, (char)'d');
	}
}

////////////////////////////////////////////////////////////////////////////////
