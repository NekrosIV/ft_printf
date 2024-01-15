/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:38:29 by kasingh           #+#    #+#             */
/*   Updated: 2023/12/23 13:12:45 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_parse_format	ft_new_parse_format(void)
{
	t_parse_format	new_parse_format;

	new_parse_format.plus = 0;
	new_parse_format.moin = 0;
	new_parse_format.width = 0;
	new_parse_format.precision = 0;
	new_parse_format.specifier = 0;
	new_parse_format.zero = 0;
	new_parse_format.dot = 0;
	new_parse_format.space = 0;
	new_parse_format.sharp = 0;
	return (new_parse_format);
}

int	ft_parse_format2(t_parse_format format_info, const char *str, int i,
		va_list arg)
{
	if (str[i] >= '0' && str[i] <= '9' && str[i - 1] != '.')
	{
		format_info.width = ft_atoi(&str[i]);
		while (str[i] && (str[i] >= '0' && str[i] <= '9'))
			i++;
	}
	if (str[i] == '.')
	{
		format_info.dot = 1;
		i++;
	}
	if (format_info.dot == 1)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			format_info.precision = ft_atoi(&str[i]);
			while (str[i] && (str[i] >= '0' && str[i] <= '9'))
				i++;
		}
	}
	if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd'
		|| str[i] == 'i' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X'
		|| str[i] == '%')
		format_info.specifier = str[i];
	return (ft_check_format(format_info, arg));
}

int	ft_parse_format(const char *str, va_list arg)
{
	t_parse_format	format_info;
	int				i;

	format_info = ft_new_parse_format();
	i = 0;
	while (str[i] && (str[i] == '-' || str[i] == '+' || str[i] == '0'
			|| str[i] == '.' || str[i] == ' ' || str[i] == '#'))
	{
		if (str[i] == '-')
			format_info.moin = 1;
		else if (str[i] == '+')
			format_info.plus = 1;
		else if (str[i] == '0')
			format_info.zero = 1;
		else if (str[i] == '.')
			format_info.dot = 1;
		else if (str[i] == ' ')
			format_info.space = 1;
		else if (str[i] == '#')
			format_info.sharp = 1;
		i++;
	}
	i = ft_parse_format2(format_info, str, i, arg);
	return (i);
}
