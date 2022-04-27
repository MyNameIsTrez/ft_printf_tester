/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_get_pointer.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/07 15:49:35 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#define _GNU_SOURCE
#include "ft_printf_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(pft_get_pointer)
{
	{
		test_get_type_string(pft_get_pointer, "0x", "1", 1);
	}
	{
		unsigned int	a = 5;
		unsigned int	*b = &a;
		char			*str = NULL;

		asprintf(&str, "%lx", (unsigned long)b);
		// str[0] = 'E';
		test_get_type_string(pft_get_pointer, "0x", str, b);
		free(str);
	}
}

////////////////////////////////////////////////////////////////////////////////
