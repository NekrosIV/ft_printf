/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:26:29 by kasingh           #+#    #+#             */
/*   Updated: 2023/12/29 10:03:49 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrl(char *str, int n)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i] && i < n)
	{
		len = len + ft_putchar(str[i]);
		i++;
	}
	return (len);
}

int	ft_print_str(t_parse_format f, char *str)
{
	int		len;
	char	c;

	len = 0;
	c = ' ';
	if (!str && (f.dot == 0 || f.precision >= 6))
		str = "(null)";
	else if (!str && f.dot != 0)
		str = "\0";
	if (!f.dot || f.precision >= (int)ft_strlen(str) || f.precision < 0)
		f.precision = ft_strlen(str);
	if (f.moin == 0 && f.width > f.precision)
		len = len + ft_put_space_or_0(f.width - f.precision, c);
	len = len + ft_putstrl(str, f.precision);
	if (f.moin == 1 && f.width > f.precision)
		len = len + ft_put_space_or_0(f.width - f.precision, c);
	return (len);
}
