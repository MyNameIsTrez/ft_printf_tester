/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_tests.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:42:16 by sbos          #+#    #+#                 */
/*   Updated: 2022/05/19 12:37:11 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef FT_PRINTF_TESTS_H
# define FT_PRINTF_TESTS_H

////////////////////////////////////////////////////////////////////////////////

// # include "tests.h"

// # include "libft_tests.h"
// # include "../../libft_tester/tests/libft_tests.h"
// # include "/Users/sbos/Documents/Programming/Project-Testers/libft_tester/tests/libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

# include "ft_printf.h"

# include "test_get_type_strings.h"

# include "ctester.h"

////////////////////////////////////////////////////////////////////////////////

# include <fcntl.h>

////////////////////////////////////////////////////////////////////////////////

extern int output_fd;
extern int ft_output_fd;

extern FILE *output_filestream;
extern FILE *ft_output_filestream;

# define get_output(fn, buf, ret, fd, filestream)								\
{																				\
	int	stdout_fd = dup(STDOUT_FILENO);											\
	dup2(fd, STDOUT_FILENO);													\
	ret = fn;																	\
	fflush(NULL);																\
	fseek(filestream, 0, SEEK_END);												\
	long file_size = ftell(filestream);											\
	buf = malloc((size_t)file_size + 1);										\
	ft_memset(buf, '\0', (size_t)file_size + 1);								\
	lseek(fd, 0, SEEK_SET);														\
	read(fd, buf, (size_t)file_size);											\
	dup2(stdout_fd, STDOUT_FILENO);												\
}

#define	compare_printfs(...)													\
{																				\
	char *buf;																	\
	int ret;																	\
	char *ft_buf;																\
	int ft_ret;																	\
																				\
	get_output(printf(__VA_ARGS__), buf, ret, output_fd, output_filestream);						\
	get_output(ft_printf(__VA_ARGS__), ft_buf, ft_ret, ft_output_fd, ft_output_filestream);			\
	massert(buf, ft_buf);														\
	massert(ret, ft_ret);														\
	free(buf);																	\
	free(ft_buf);																\
}

////////////////////////////////////////////////////////////////////////////////
// These are helper functions from bonus/src
// that aren't in bonus/src/ft_printf_bonus.h as they are normally private.

void	pft_parse_options_type(char **format, unsigned char *type);
void	pft_parse_field_width(char **format, size_t *field_width);
void	pft_parse_flags(char **format, t_flags *flags);
void	pft_parse_precision(char **format, ssize_t *precision);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
