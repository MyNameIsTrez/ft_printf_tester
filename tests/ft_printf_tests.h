/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_tests.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:42:16 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/25 15:12:01 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef FT_PRINTF_TESTS_H
# define FT_PRINTF_TESTS_H

////////////////////////////////////////////////////////////////////////////////

# include "ft_printf.h"

# include "tests_get_type_strings/test_get_type_strings.h"

# include "ctester.h"

////////////////////////////////////////////////////////////////////////////////

# include <fcntl.h>

////////////////////////////////////////////////////////////////////////////////

extern int output_fd;
extern int ft_output_fd;

extern FILE *output_filestream;
extern FILE *ft_output_filestream;

extern int real_stdout;

# define get_output(fn, buf, ret, fd, filestream)\
{\
	dup2(fd, STDOUT_FILENO);\
 	lseek(fd, 0, SEEK_SET);\
	fseek(filestream, 0, SEEK_SET);\
	ftruncate(fd, 0);\
	ret = fn;\
	fflush(NULL);\
	fseek(filestream, 0, SEEK_END);\
	long file_size = ftell(filestream);\
	buf = malloc((size_t)file_size + 1);\
	ft_memset(buf, '\0', (size_t)file_size + 1);\
	lseek(fd, 0, SEEK_SET);\
	read(fd, buf, (size_t)file_size);\
	dup2(real_stdout, STDOUT_FILENO);\
}

#define	compare_printfs(...)\
{\
	char *buf;\
	int ret;\
	char *ft_buf;\
	int ft_ret;\
\
	get_output(printf(__VA_ARGS__), buf, ret, output_fd, output_filestream);\
	get_output(ft_printf(__VA_ARGS__), ft_buf, ft_ret, ft_output_fd, ft_output_filestream);\
	m_safe_assert(int, ft_ret, ret, -1, false);\
	if (!was_malloc_unstable AND !was_write_unstable)\
		massert(ft_buf, buf);\
	was_malloc_unstable = false;\
	was_write_unstable = false;\
	free(buf);\
	free(ft_buf);\
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
