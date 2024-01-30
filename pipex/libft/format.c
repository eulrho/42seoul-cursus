/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:25:46 by erho              #+#    #+#             */
/*   Updated: 2024/01/12 20:47:56 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	print_format(char c, va_list *argptr)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*argptr, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*argptr, char *)));
	else if (c == 'p')
		return (print_hex_addr(va_arg(*argptr, unsigned long long)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_base(va_arg(*argptr, int), "0123456789"));
	else if (c == 'u')
		return (conv_nbr("0123456789", va_arg(*argptr, unsigned int), 10));
	else if (c == 'x' || c == 'X')
		return (print_hex(c, va_arg(*argptr, unsigned int)));
	else if (c > 0)
		return (ft_putchar(c));
	return (0);
}
