/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:31:18 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/03 11:02:14 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_space_or_0(int n, char c)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		len = len + ft_putchar(c);
		n--;
	}
	return (len);
}

char	ft_signe(t_parse_format f, int n)
{
	if (f.plus == 1 && n >= 0)
		return ('+');
	return ('-');
}

int	ft_print_nbr(t_parse_format f, int n, char *nbr, char c)
{
	int	len;
	int	s;
	int	nbr_len;

	s = 0;
	len = 0;
	nbr_len = ft_strlen(nbr);
	if ((f.plus == 1 || n < 0))
		s = 1;
	if ((f.space == 1 && f.plus == 0 && n >= 0))
		len = len + ft_put_space_or_0(1, ' ');
	if ((f.moin == 1 || (f.zero == 1 && f.dot == 0)) && s == 1)
		len = len + ft_putchar(ft_signe(f, n));
	if (f.dot == 0 || (f.precision < nbr_len && n != 0))
		f.precision = nbr_len;
	if (f.moin == 0 && f.width > f.precision + s)
		len = len + ft_put_space_or_0(f.width - f.space - f.precision - s, c);
	if (s == 1 && f.moin == 0 && (f.zero == 0 || f.dot == 1))
		len = len + ft_putchar(ft_signe(f, n));
	len = len + ft_put_space_or_0(f.precision - nbr_len, '0');
	len = len + ft_putstrl(nbr, f.precision);
	if (f.moin == 1 && f.width > f.precision + s)
		len = len + ft_put_space_or_0(f.width - f.space - f.precision - s, c);
	return (len);
}

int	ft_print_d_i(t_parse_format f, int n)
{
	int		len;
	char	*nbr;
	char	c;

	len = 0;
	c = ' ';
	nbr = ft_itoa_nosigne(n);
	if (n < 0)
		f.plus = 0;
	if (f.zero == 1 && f.dot == 0)
		c = '0';
	if (f.plus == 1 || n < 0)
		f.space = 0;
	len = len + ft_print_nbr(f, n, nbr, c);
	free(nbr);
	return (len);
}
