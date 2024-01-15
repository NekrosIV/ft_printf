/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:14:41 by kasingh           #+#    #+#             */
/*   Updated: 2024/01/03 10:45:47 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(t_parse_format f, unsigned long int n)
{
	int		len;
	char	*nbr;
	int		c;
	int		nbr_len;

	len = 0;
	c = 5;
	nbr = ft_itoa_p(n);
	nbr_len = ft_strlen(nbr);
	if (n != 0)
	{
		c = 2;
		f.precision = nbr_len;
	}
	if (f.moin == 0 && f.width > f.precision)
		len = len + ft_put_space_or_0(f.width - f.precision - c, ' ');
	if (n != 0)
		len = len + ft_putstrl("0x", 2);
	else
		len = len + ft_putstrl("(nil)", 5);
	len = len + ft_putstrl(nbr, f.precision);
	if (f.moin == 1 && f.width > f.precision)
		len = len + ft_put_space_or_0(f.width - f.precision - c, ' ');
	free(nbr);
	return (len);
}
