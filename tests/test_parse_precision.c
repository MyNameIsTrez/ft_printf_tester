/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_precision.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/22 16:42:09 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(parse_precision)
{
	{
		char	*format = ".42d";
		t_options	options;

		pft_initialize_options(&options);
		parse_precision(&format, &options.precision);

		// printf("'%7.42d'\n",  0) -> '000000000000000000000000000000000000000000'
		// printf("'%7.42d'\n", 42) -> '000000000000000000000000000000000000000042'
		massert(options.precision, 42l);
		massert(*format, (char)'d')
	}

	{
		char	*format = ".1d";
		t_options	options;

		pft_initialize_options(&options);
		parse_precision(&format, &options.precision);

		// printf("%.1d",  0) -> '0'
		// printf("%.1d", 42) -> '42'
		massert(options.precision, (ssize_t)1);
		massert(*format, (char)'d')
	}

	{
		char	*format = ".0d";
		t_options	options;

		pft_initialize_options(&options);
		parse_precision(&format, &options.precision);

		// printf("%.0d",  0) -> ''
		// printf("%.0d", 42) -> '42'
		massert(options.precision, (ssize_t)0);
		massert(*format, (char)'d')
	}

	{
		char	*format = ".d";
		t_options	options;

		pft_initialize_options(&options);
		parse_precision(&format, &options.precision);

		// printf("%.d",  0) -> ''
		// printf("%.d", 42) -> '42'
		massert(options.precision, (ssize_t)0);
		massert(*format, (char)'d')
	}

	{
		char	*format = "d";
		t_options	options;

		pft_initialize_options(&options);
		parse_precision(&format, &options.precision);

		// printf("'%d'\n" , 0) -> '0'
		// printf("'%.0d'\n", 0) -> ''
		massert(options.precision, (ssize_t)-1);
		massert(*format, (char)'d')
	}
}

////////////////////////////////////////////////////////////////////////////////
