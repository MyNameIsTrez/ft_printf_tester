/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_fix_priorities.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/01 18:09:27 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

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
}

////////////////////////////////////////////////////////////////////////////////
