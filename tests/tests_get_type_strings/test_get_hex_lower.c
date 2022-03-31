/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_get_hex_lower.c                               :+:    :+:            */
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

Test(pft_get_hex_lower)
{
	test_get_type_string(pft_get_hex_lower, "", "0", 0);

	test_get_type_string(pft_get_hex_lower, "", "1", 1);
	test_get_type_string(pft_get_hex_lower, "", "9", 9);
	test_get_type_string(pft_get_hex_lower, "", "a", 10);
	test_get_type_string(pft_get_hex_lower, "", "f", 15);
	test_get_type_string(pft_get_hex_lower, "", "10", 16);
	test_get_type_string(pft_get_hex_lower, "", "11", 17);

	test_get_type_string(pft_get_hex_lower, "", "ffffffff", -1);
	test_get_type_string(pft_get_hex_lower, "", "fffffff7", -9);
	test_get_type_string(pft_get_hex_lower, "", "fffffff6", -10);
	test_get_type_string(pft_get_hex_lower, "", "fffffff1", -15);
	test_get_type_string(pft_get_hex_lower, "", "fffffff0", -16);
	test_get_type_string(pft_get_hex_lower, "", "ffffffef", -17);
}

////////////////////////////////////////////////////////////////////////////////
