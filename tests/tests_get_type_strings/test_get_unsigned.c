/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_get_unsigned.c                                :+:    :+:            */
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

Test(pft_get_unsigned)
{
	test_get_type_string(pft_get_unsigned, "", "0", 0);
	test_get_type_string(pft_get_unsigned, "", "1", 1);
	test_get_type_string(pft_get_unsigned, "", "4294967295", -1);
	test_get_type_string(pft_get_unsigned, "", "10", 10);
}

////////////////////////////////////////////////////////////////////////////////
