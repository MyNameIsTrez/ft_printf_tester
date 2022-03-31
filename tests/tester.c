/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tester.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:05:05 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/31 15:56:48 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

# include <stdio.h>		// printf()
# include <stdlib.h>	// EXIT_SUCCESS

////////////////////////////////////////////////////////////////////////////////

t_list *g_tests_lst = NULL;

////////////////////////////////////////////////////////////////////////////////

static bool	str_in_arr(char *str, char *arr[], size_t sizeof_arr)
{
	size_t i = 0;
	while (i < sizeof_arr / sizeof(char *))
	{
		if (ft_strcmp(arr[i], str) == 0)
			return (true);
		i++;
	}
	return (false);
}

static void	run_tests_exclude(char *exclude_tests[], size_t sizeof_exclude_tests)
{
	t_list	*lst = g_tests_lst;
	while (lst != NULL)
	{
		t_fn_info *fn = lst->content;
		if (!str_in_arr(fn->fn_name, exclude_tests, sizeof_exclude_tests))
		{
			printf("Testing function '%s'\n", fn->fn_name);
			fn->fn_ptr();
		}
		lst = lst->next;
	}
}

static void	run_tests_include(char *include_tests[], size_t sizeof_include_tests)
{
	t_list	*lst = g_tests_lst;
	while (lst != NULL)
	{
		t_fn_info *fn = lst->content;
		if (str_in_arr(fn->fn_name, include_tests, sizeof_include_tests))
		{
			printf("Testing function '%s'\n", fn->fn_name);
			fn->fn_ptr();
		}
		lst = lst->next;
	}
}

////////////////////////////////////////////////////////////////////////////////

int	main(void)
{
	(void)run_tests_exclude;
	(void)run_tests_include;
	printf("\nRunning tests...\n");
	char *exclude_tests[] = {
		// "pft_get_pointer",
	};
	run_tests_exclude(exclude_tests, sizeof(exclude_tests));
	// char *include_tests[] = {
	// 	"ft_printf"
	// };
	// run_tests_include(include_tests, sizeof(include_tests));
	printf("Tests ran successfully!\n\n");
	#ifndef linux
		#if defined(__has_feature)
			# if __has_feature(address_sanitizer)
			# else
				system("leaks tester");
			# endif
		#else
			#ifdef __SANITIZE_ADDRESS__
			#else
				system("leaks tester");
			#endif
		#endif
	#endif
	return (EXIT_SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
