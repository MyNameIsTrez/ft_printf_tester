/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_get_string.c                                  :+:    :+:            */
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

Test(pft_get_string)
{
	test_get_type_string(pft_get_string, "", "", "");
	test_get_type_string(pft_get_string, "", "1", "1");
	test_get_type_string(pft_get_string, "", "42", "42");
	test_get_type_string(pft_get_string, "", "hello", (char []){'h', 'e', 'l', 'l', 'o', '\0'});
}

////////////////////////////////////////////////////////////////////////////////
