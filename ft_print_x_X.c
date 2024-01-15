/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_X.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 11:22:59 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/03 12:44:04 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_base_16(t_parse_format f, int nbr_len, char *nbr, char *str)
{
	int		s;
	char	c;
	int		len;

	len = 0;
	s = 0;
	c = ' ';
	if (f.zero == 1 && f.dot == 0)
		c = '0';
	if (f.dot == 0 || (f.precision < nbr_len && ft_strncmp(nbr, "0", nbr_len)))
		f.precision = nbr_len;
	if (f.sharp == 1 && ft_strncmp(nbr, "0", nbr_len))
		s = 2;
	if ((f.moin == 1 || f.zero == 1) && s == 2)
		len = len + ft_putstrl(str, 2);
	if (f.moin == 0 && f.width > f.precision + s)
		len = len + ft_put_space_or_0(f.width - f.space - f.precision - s, c);
	if (s == 2 && f.moin == 0 && f.zero == 0)
		len = len + ft_putstrl(str, 2);
	len = len + ft_put_space_or_0(f.precision - nbr_len, '0');
	len = len + ft_putstrl(nbr, f.precision);
	if (f.moin == 1 && f.width > f.precision + s)
		len = len + ft_put_space_or_0(f.width - f.space - f.precision - s, c);
	return (len);
}

int	ft_print_x_x(t_parse_format f, unsigned int n)
{
	int		len;
	char	*nbr;
	int		nbr_len;
	char	*str;

	len = 0;
	if (f.specifier == 'x')
	{
		nbr = ft_itoa_base_16(n, 'a');
		str = "0x";
	}
	else
	{
		nbr = ft_itoa_base_16(n, 'A');
		str = "0X";
	}
	nbr_len = ft_strlen(nbr);
	if (f.dot == 1)
		f.zero = 0;
	len = ft_print_base_16(f, nbr_len, nbr, str);
	free(nbr);
	return (len);
}
