/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_initialize_state.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/10 12:43:59 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

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
