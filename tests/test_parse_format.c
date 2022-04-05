/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_format.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/04 16:38:44 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(pft_parse_format)
{
	{
		t_options	options;
		char		*format = "#0- +42d";

		pft_initialize_options(&options);
		pft_parse_format(&format, &options);

		massert(options.flags.alternate, (bool)true);
		massert(options.flags.zero_pad, (bool)false);
		massert(options.flags.pad_right, (bool)true);
		massert(options.flags.plus_space, (bool)true);
		massert(options.flags.plus_sign, (bool)true);

		massert(options.field_width, (size_t)42);
		massert(options.precision, (ssize_t)-1);
		massert(*format, (char)'d');
	}

	{
		t_options	options;
		char		*format = "42d";

		pft_initialize_options(&options);
		pft_parse_format(&format, &options);

		massert(options.flags.alternate, (bool)false);
		massert(options.flags.zero_pad, (bool)false);
		massert(options.flags.pad_right, (bool)false);
		massert(options.flags.plus_space, (bool)false);
		massert(options.flags.plus_sign, (bool)false);

		massert(options.field_width, (size_t)42);
		massert(options.precision, (ssize_t)-1);
		massert(*format, (char)'d');
	}

	{
		t_options	options;
		char		*format = "d";

		pft_initialize_options(&options);
		pft_parse_format(&format, &options);

		massert(options.flags.alternate, (bool)false);
		massert(options.flags.zero_pad, (bool)false);
		massert(options.flags.pad_right, (bool)false);
		massert(options.flags.plus_space, (bool)false);
		massert(options.flags.plus_sign, (bool)false);

		massert(options.field_width, (size_t)0);
		massert(options.precision, (ssize_t)-1);
		massert(*format, (char)'d');
	}

	{
		t_options	options;
		char		*format = "0d";

		pft_initialize_options(&options);
		pft_parse_format(&format, &options);

		massert(options.flags.alternate, (bool)false);
		massert(options.flags.zero_pad, (bool)true);
		massert(options.flags.pad_right, (bool)false);
		massert(options.flags.plus_space, (bool)false);
		massert(options.flags.plus_sign, (bool)false);

		massert(options.field_width, (size_t)0);
		massert(options.precision, (ssize_t)-1);
		massert(*format, (char)'d');
	}
}

////////////////////////////////////////////////////////////////////////////////
