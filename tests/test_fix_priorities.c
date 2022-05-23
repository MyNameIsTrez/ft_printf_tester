/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_fix_priorities.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/05/23 16:10:39 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_tests.h"

////////////////////////////////////////////////////////////////////////////////

void	pft_fix_priorities(t_options *options);

Test(pft_fix_priorities)
{
	{
		t_options	options;

		pft_initialize_options(&options);

		options.flags.zero_pad = true;
		options.precision = 3;

		pft_fix_priorities(&options);

		// printf("'%04d'\n", 42) -> '0042'
		// printf("'%04.3d'\n", 42) -> ' 042'
		massert(options.flags.zero_pad, (bool)false);
	}
	{
		t_options	options;

		pft_initialize_options(&options);

		options.flags.plus_sign = true;
		options.flags.plus_space = true;

		pft_fix_priorities(&options);

		massert(options.flags.plus_space, (bool)false);
		massert(options.flags.plus_sign, (bool)true);
	}
}

////////////////////////////////////////////////////////////////////////////////
