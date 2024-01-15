/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:02:10 by kasingh           #+#    #+#             */
/*   Updated: 2023/12/29 11:10:12 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(t_parse_format f, unsigned int n)
{
	int		len;
	char	*nbr;
	char	c;
	int		nbr_len;

	len = 0;
	c = ' ';
	nbr = ft_itoa_unsigned(n);
	nbr_len = ft_strlen(nbr);
	if (f.zero == 1 && f.dot == 0)
		c = '0';
	if (f.dot == 0 || (f.precision < nbr_len && n != 0))
		f.precision = nbr_len;
	if (f.moin == 0 && f.width > f.precision)
		len = len + ft_put_space_or_0(f.width - f.space - f.precision, c);
	len = len + ft_put_space_or_0(f.precision - nbr_len, '0');
	len = len + ft_putstrl(nbr, f.precision);
	if (f.moin == 1 && f.width > f.precision)
		len = len + ft_put_space_or_0(f.width - f.space - f.precision, c);
	free(nbr);
	return (len);
}
