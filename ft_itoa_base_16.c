/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_16.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:02:11 by kasingh           #+#    #+#             */
/*   Updated: 2023/12/23 12:06:08 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digit_base(unsigned int n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / base;
		count++;
	}
	return (count);
}

static char	ft_digit_to_char(unsigned int digit, char c)
{
	if (digit < 10)
		return (digit + '0');
	else
		return (digit - 10 + c);
}

char	*ft_itoa_base_16(unsigned int n, char c)
{
	int		digit;
	char	*result;
	int		i;

	digit = ft_count_digit_base(n, 16);
	result = malloc((digit + 1) * sizeof(char));
	if (result == 0)
		return (0);
	i = digit;
	while (0 < i)
	{
		result[--i] = ft_digit_to_char(n % 16, c);
		n = n / 16;
	}
	result[digit] = '\0';
	return (result);
}
