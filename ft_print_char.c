/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:34:08 by kasingh           #+#    #+#             */
/*   Updated: 2023/12/23 11:36:36 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_char(t_parse_format f, char c)
{
	int	len;

	len = 0;
	if (f.moin == 0 && f.width > f.precision)
		len = len + ft_put_space_or_0(f.width - 1, ' ');
	len = len + ft_putchar(c);
	if (f.moin == 1 && f.width > f.precision)
		len = len + ft_put_space_or_0(f.width - 1, ' ');
	return (len);
}
