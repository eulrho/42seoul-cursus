/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:20:04 by erho              #+#    #+#             */
/*   Updated: 2023/10/10 20:16:00 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			res[12];
	unsigned int	nbr;
	size_t			i;

	res[ft_nbrlen(n)] = '\0';
	i = ft_nbrlen(n) - 1;
	if (n == 0)
		res[0] = '0';
	else
	{
		if (n < 0)
		{
			res[0] = '-';
			nbr = (unsigned int)n * -1;
		}
		else
			nbr = (unsigned int)n;
		while (nbr)
		{
			res[i] = nbr % 10 + '0';
			nbr /= 10;
			i--;
		}
	}
	write(fd, &res, ft_strlen(res));
}
