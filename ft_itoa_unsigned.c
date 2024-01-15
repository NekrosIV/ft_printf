/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:10:26 by kasingh           #+#    #+#             */
/*   Updated: 2023/12/23 11:59:13 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_count_digit(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	*ft_new_str(char *result, unsigned int n, int digit)
{
	int	i;

	i = digit;
	while (0 < i)
	{
		result[--i] = n % 10 + '0';
		n = n / 10;
	}
	result[digit] = '\0';
	return (result);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char	*result;
	int		digit;

	digit = ft_count_digit(n);
	result = malloc((digit + 1) * sizeof(char));
	if (result == 0)
		return (0);
	return (ft_new_str(result, n, digit));
}
