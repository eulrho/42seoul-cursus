/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:06:16 by erho              #+#    #+#             */
/*   Updated: 2024/01/18 19:23:23 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		len;
	int		idx;
	int		temp;

	len = 0;
	idx = 0;
	va_start(argptr, str);
	while (str[idx])
	{
		if (str[idx] == '%')
			temp = print_format(str[++idx], &argptr);
		else
			temp = ft_putchar(str[idx]);
		if (temp >= 0)
			len += temp;
		else
			ft_error(WRITE);
		if (str[idx] != '\0')
			idx++;
	}
	va_end(argptr);
	return (len);
}
