/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:03:20 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/03 12:49:01 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(t_parse_format format_info, va_list arg)
{
	int	len;

	len = 0;
	if (format_info.specifier == 'c')
		len = len + ft_print_char(format_info, va_arg(arg, int));
	else if (format_info.specifier == '%')
		len = len + ft_print_char(format_info, '%');
	else if (format_info.specifier == 's')
		len = len + ft_print_str(format_info, va_arg(arg, char *));
	else if (format_info.specifier == 'd' || format_info.specifier == 'i')
		len = len + ft_print_d_i(format_info, va_arg(arg, int));
	else if (format_info.specifier == 'u')
		len = len + ft_print_u(format_info, va_arg(arg, unsigned int));
	else if (format_info.specifier == 'p')
		len = len + ft_print_p(format_info, va_arg(arg, unsigned long int));
	else if (format_info.specifier == 'x' || format_info.specifier == 'X')
		len = len + ft_print_x_x(format_info, va_arg(arg, unsigned int));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (format == 0)
		return (-1);
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len = len + ft_parse_format(&format[++i], arg);
			while (format[i] && !ft_strchr("csidpuxX%", format[i]))
				i++;
		}
		else
			len = len + ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (len);
}

// #include "ft_printf.h"
// #include <stdio.h>
// #define TEST "[%#x]\n", 0

// int	main(void)
// {
// 	int	i;
// 	int	j;

// 	i = ft_printf(TEST);
// 	j = printf(TEST);
// 	printf("i = %d\nj = %d\n", i, j);
// 	return (0);
// }