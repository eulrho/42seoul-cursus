/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:45:05 by erho              #+#    #+#             */
/*   Updated: 2023/11/08 16:43:25 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_hex(char *base, unsigned long long n)
{
	char	*buff;
	int		len;
	int		res;

	if (n == 0)
		return (write(1, "0", 1));
	len = ft_nbrlen_base(n, 16);
	buff = (char *)malloc(sizeof(char) * (len + 1));
	if (buff == NULL)
		return (-1);
	buff[len] = '\0';
	res = len;
	while (n)
	{
		buff[--len] = base[n % 16];
		n /= 16;
	}
	if (write(1, buff, res) < 0)
		res = -1;
	free(buff);
	return (res);
}

int	print_hex_addr(unsigned long long nbr)
{
	int	len;
	int	temp;

	temp = 0;
	len = write(1, "0x", 2);
	if (len == -1)
		return (-1);
	temp = conv_hex("0123456789abcdef", nbr);
	if (temp == -1)
		len = -1;
	else
		len += temp;
	return (len);
}

int	print_hex(char c, unsigned int nbr)
{
	if (c == 'x')
		return (conv_nbr("0123456789abcdef", nbr, 16));
	return (conv_nbr("0123456789ABCDEF", nbr, 16));
}
