/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:42:16 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/04 18:54:26 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef TESTS_H
# define TESTS_H

////////////////////////////////////////////////////////////////////////////////

# include "ft_printf.h"

# include "test_get_type_strings.h"

# include "massert.h"

////////////////////////////////////////////////////////////////////////////////

# include <fcntl.h>

////////////////////////////////////////////////////////////////////////////////

typedef void (*void_fn)(void);

typedef struct s_fn_info {
	char	*fn_name;
	void_fn	fn_ptr;
}	t_fn_info;

////////////////////////////////////////////////////////////////////////////////

extern t_list	*g_tests_lst;

////////////////////////////////////////////////////////////////////////////////

#define Test(name)																\
	void test_##name(void);														\
	__attribute__((constructor))												\
	void add_test_##name(void)													\
	{																			\
		static t_fn_info fn_info = {.fn_name = #name, .fn_ptr = &test_##name};	\
		ft_lst_new_front(&g_tests_lst, &fn_info);								\
	}																			\
	void test_##name(void)

////////////////////////////////////////////////////////////////////////////////

# define get_output(fn, buf, ret)													\
{																					\
	int	stdout_fd = dup(STDOUT_FILENO);												\
	int const	fd = open("/tmp/" #fn "_test", O_RDWR | O_CREAT | O_TRUNC, 0640);	\
	dup2(fd, STDOUT_FILENO);														\
	ret = fn;																		\
	fflush(NULL);																	\
	FILE *f = fdopen(fd, "rw");														\
	fseek(f, 0, SEEK_END);															\
	long file_size = ftell(f);														\
	buf = malloc((size_t)file_size + 1);											\
	ft_memset(buf, '\0', (size_t)file_size + 1);									\
	lseek(fd, 0, SEEK_SET);															\
	read(fd, buf, (size_t)file_size);												\
	close(fd);																		\
	dup2(stdout_fd, STDOUT_FILENO);													\
}

#define	compare_printfs(...)													\
{																				\
	char *buf;																	\
	int ret;																	\
	char *ft_buf;																\
	int ft_ret;																	\
																				\
	get_output(printf(__VA_ARGS__), buf, ret);									\
	get_output(ft_printf(__VA_ARGS__), ft_buf, ft_ret);							\
	massert(buf, ft_buf);														\
	massert(ret, ft_ret);														\
	free(buf);																	\
	free(ft_buf);																\
}

////////////////////////////////////////////////////////////////////////////////
// These are helper functions from bonus/src
// that aren't in bonus/src/ft_printf_bonus.h as they are normally private.

void	parse_options_type(char **format, unsigned char *type);
void	parse_field_width(char **format, size_t *field_width);
void	parse_flags(char **format, t_flags *flags);
void	parse_precision(char **format, ssize_t *precision);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
