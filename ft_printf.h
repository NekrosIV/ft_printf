/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:30:37 by kasingh           #+#    #+#             */
/*   Updated: 2023/12/29 11:16:06 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_parse_format
{
	int		plus;
	int		moin;
	int		width;
	int		precision;
	char	specifier;
	int		zero;
	int		dot;
	int		space;
	int		sharp;
}			t_parse_format;

int			ft_printf(const char *format, ...);
int			ft_putchar(char c);
int			ft_print_char(t_parse_format f, char c);
int			ft_print_str(t_parse_format f, char *str);
int			ft_putstrl(char *str, int n);
char		*ft_itoa_nosigne(int n);
int			ft_print_d_i(t_parse_format f, int n);
int			ft_print_u(t_parse_format f, unsigned int n);
int			ft_print_p(t_parse_format f, unsigned long int n);
int			ft_put_space_or_0(int n, char c);
int			ft_parse_format(const char *str, va_list arg);
int			ft_parse_format2(t_parse_format format_info, const char *str, int i,
				va_list arg);
int			ft_check_format(t_parse_format format_info, va_list arg);
char		*ft_itoa_unsigned(unsigned int n);
char		*ft_itoa_base_16(unsigned int n, char c);
int			ft_print_x_x(t_parse_format f, unsigned int n);
char		*ft_itoa_p(unsigned long int n);

#endif