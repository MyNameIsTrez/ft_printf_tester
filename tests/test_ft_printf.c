/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_printf.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 17:56:28 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/25 16:25:12 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_tests.h"

////////////////////////////////////////////////////////////////////////////////

#include <stdint.h>
#include <limits.h>

////////////////////////////////////////////////////////////////////////////////

int output_fd = -1;
int ft_output_fd = -1;

FILE *output_filestream = NULL;
FILE *ft_output_filestream = NULL;

int real_stdout = -1;

BeforeMain(set_fd)
{
	output_fd = open("/tmp/pft_output", O_RDWR | O_CREAT | O_TRUNC, 0640);
	ft_output_fd = open("/tmp/ft_pft_output", O_RDWR | O_CREAT | O_TRUNC, 0640);

	output_filestream = fdopen(output_fd, "rw");
	ft_output_filestream = fdopen(ft_output_fd, "rw");

	real_stdout = dup(STDOUT_FILENO);
}

AfterMain(set_fd)
{
	if (output_filestream != NULL)
		fclose(output_filestream);
	if (ft_output_filestream != NULL)
		fclose(ft_output_filestream);

	if (real_stdout != -1)
		close(real_stdout);

	remove("/tmp/pft_output");
	remove("/tmp/ft_pft_output");
}

////////////////////////////////////////////////////////////////////////////////

Test(ft_printf)
{
	{
		compare_printfs("%c", 'a');
		compare_printfs("%.c", 'a');
		compare_printfs("%-c", 'a');
		compare_printfs("%-.c", 'a');
		compare_printfs("%1c", 'a');
		compare_printfs("%3c", 'a');
		compare_printfs("%-3c", 'a');
		compare_printfs("%1c", '\0');
	}
	{
		compare_printfs("%s", "");
		compare_printfs("%s", "foo");
		compare_printfs("%-s", "foo");
		compare_printfs("%.s", "foo");
		compare_printfs("%-.s", "foo");
		compare_printfs("%1s", "foo");
		compare_printfs("%5s", "foo");
		compare_printfs("%-5s", "foo");
		compare_printfs("%.2s", "foo");
		compare_printfs("%-.5s", "foo");
	}
	{
		compare_printfs("%p", (void *)0x42);
		#ifndef linux
		compare_printfs("%p", (void *)0x0);
		compare_printfs("%.p", (void *)0x0);
		#endif
		compare_printfs("%.p", (void *)0x7);
		compare_printfs("%1p", (void *)0x42);
		compare_printfs("%5p", (void *)0x42);
		compare_printfs("%-5p", (void *)0x42);
	}
	{
		compare_printfs("%d", 5);
		compare_printfs("%d", 0);
		compare_printfs("%d", -5);
		compare_printfs("%d", 51);
		compare_printfs("%.1d", 51);
		compare_printfs("%.4d", 51);
		compare_printfs("%d", INT32_MAX);
		compare_printfs("%d", INT32_MIN);
		compare_printfs("%1d", 42);
		compare_printfs("%5d", 42);
		compare_printfs("%-5d", 42);
		compare_printfs("%1d", -42);
		compare_printfs("%5d", -42);
		compare_printfs("%-5d", -42);
		compare_printfs("% d", 5);
		compare_printfs("%+d", 5);
		compare_printfs("% .d", 0);
		compare_printfs("%+.d", 0);
	}
	{
		compare_printfs("%u", 5);
		compare_printfs("%u", 0);
		compare_printfs("%u", -5);
		compare_printfs("%u", 51);
		compare_printfs("%.1u", 51);
		compare_printfs("%.4u", 51);
		compare_printfs("%u", UINT32_MAX);
		compare_printfs("%1u", 42);
		compare_printfs("%5u", 42);
		compare_printfs("%-5u", 42);
	}
	{
		compare_printfs("%x", 5);
		compare_printfs("%#x", 0);
		compare_printfs("%#.x", 0);
		compare_printfs("%.1x", 51);
		compare_printfs("%.4x", 51);
		compare_printfs("%1x", 0x42);
		compare_printfs("%5x", 0x42);
		compare_printfs("%-5x", 0x42);
	}
	{
		compare_printfs("%X", 5);
		compare_printfs("%#X", 0);
		compare_printfs("%#.X", 0);
		compare_printfs("%.1X", 51);
		compare_printfs("%.4X", 51);
		compare_printfs("%1X", 0x42);
		compare_printfs("%5X", 0x42);
		compare_printfs("%-5X", 0x42);
	}
	{
		compare_printfs("%%");
		compare_printfs("%.%");
		compare_printfs("%.1%");
		compare_printfs("%.5%");
		compare_printfs("%0%");
		compare_printfs("%01%");
		#ifndef linux
		compare_printfs("%05%");
		#endif
		compare_printfs("%1%");
		#ifndef linux
		compare_printfs("%5%");
		compare_printfs("%-5%");
		compare_printfs("%#5%");
		compare_printfs("% 5%");
		compare_printfs("%+5%");
		#endif
	}
	{
		compare_printfs("");
		compare_printfs("foo");
		compare_printfs("foo%d", 42);
		compare_printfs("foo%d%d", 42, 69);
		compare_printfs("%dfoo", 42);
		compare_printfs("%d%dfoo", 42, 69);
		compare_printfs("foo%dbar", 42);
		compare_printfs("%dfoo%dbar", 42, 69);
		compare_printfs("foo%dbar%d", 42, 69);
		compare_printfs("%dfoo%dbar%d", 42, 69, 1337);
	}
	{
		_Pragma("GCC diagnostic push")
		_Pragma("GCC diagnostic ignored \"-Wformat\"")
		// compare_printfs("%k d");
		_Pragma("GCC diagnostic pop")
	}
	{
		_Pragma("GCC diagnostic push")
		_Pragma("GCC diagnostic ignored \"-Wformat\"")
		// compare_printfs("%");
		_Pragma("GCC diagnostic pop")
	}
	{
		compare_printfs("%+.1d, %+.1d, %+.1d, %+.1d, %+.1d, %+.1d, %+.1d, %+.1d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
		compare_printfs("%+.100d, %+.100d, %+.100d, %+.100d, %+.100d, %+.100d, %+.100d, %+.100d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
		compare_printfs("%+1.0i, %+1.0i, %+1.0i, %+1.0i, %+1.0i, %+1.0i, %+1.0i, %+1.0i", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
		compare_printfs("%100.0u, %100.0u, %100.0u, %100.0u, %100.0u, %100.0u, %100.0u, %100.0u, %100.0u, %100.0u", 0, 5, -1, -10, 100, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
		compare_printfs("%100.0x, %100.0x, %100.0x, %100.0x, %100.0x, %100.0x, %100.0x, %100.0x, %100.0x, %100.0x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
		compare_printfs("%100.0X, %100.0X, %100.0X, %100.0X, %100.0X, %100.0X, %100.0X, %100.0X, %100.0X, %100.0X", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);

		compare_printfs("%010.100d, %010.100d, %010.100d, %010.100d, %010.100d, %010.100d, %010.100d, %010.100d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
		compare_printfs("%010.100i, %010.100i, %010.100i, %010.100i, %010.100i, %010.100i, %010.100i, %010.100i", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
		compare_printfs("%0#.1x, %0#.1x, %0#.1x, %0#.1x, %0#.1x, %0#.1x, %0#.1x, %0#.1x, %0#.1x, %0#.1x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
		compare_printfs("%0#5X, %0#5X, %0#5X, %0#5X, %0#5X, %0#5X, %0#5X, %0#5X, %0#5X, %0#5X", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
	}
	{
		_Pragma("GCC diagnostic push")
		_Pragma("GCC diagnostic ignored \"-Wformat\"")
		compare_printfs("%+ d", 42);
		_Pragma("GCC diagnostic pop")
	}
	{
		compare_printfs("%-d", INT_MIN);
	}
}

////////////////////////////////////////////////////////////////////////////////
