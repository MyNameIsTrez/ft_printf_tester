/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_pft_initialize_options.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 16:41:22 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/07 15:49:35 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(pft_initialize_options)
{
	{
		t_options	options;

		pft_initialize_options(&options);

		massert(options.flags.alternate, (bool)false);
		massert(options.flags.zero_pad, (bool)false);
		massert(options.flags.pad_right, (bool)false);
		massert(options.flags.plus_space, (bool)false);
		massert(options.flags.plus_sign, (bool)false);

		massert(options.field_width, (size_t)0);
		massert(options.precision, (ssize_t)-1);
	}
}

////////////////////////////////////////////////////////////////////////////////
