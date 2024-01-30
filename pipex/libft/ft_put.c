/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:05:33 by erho              #+#    #+#             */
/*   Updated: 2024/01/18 19:23:33 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	conv_nbr(char *base, unsigned int n, int base_nb)
{
	char	*buff;
	int		len;
	int		res;

	if (n == 0)
		return (write(1, "0", 1));
	len = ft_nbrlen_base(n, base_nb);
	buff = (char *)malloc(sizeof(char) * (len + 1));
	if (buff == NULL)
		ft_error(MEMORY);
	buff[len] = '\0';
	res = len;
	while (n)
	{
		buff[--len] = base[n % base_nb];
		n /= base_nb;
	}
	res = write(1, buff, res);
	free(buff);
	return (res);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int				base_nb;
	unsigned int	n;
	int				len;
	int				temp;

	len = 0;
	if (nbr < 0)
	{
		n = (unsigned int)(nbr * -1);
		len = write(1, "-", 1);
		if (len == -1)
			ft_error(WRITE);
	}
	else
		n = (unsigned int)nbr;
	base_nb = ft_strlen(base);
	temp = conv_nbr(base, n, base_nb);
	if (temp == -1)
		len = -1;
	else
		len += temp;
	return (len);
}
