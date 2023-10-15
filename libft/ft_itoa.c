/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:21:18 by erho              #+#    #+#             */
/*   Updated: 2023/10/10 20:12:26 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(int n)
{
	size_t	cnt;

	cnt = n <= 0;
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

void	insert(char *res, int n)
{
	size_t			i;
	unsigned int	nbr;
	size_t			n_len;

	n_len = ft_nbrlen(n);
	res[n_len] = '\0';
	i = n_len - 1;
	if (n < 0)
	{
		res[0] = '-';
		nbr = (unsigned int)n * -1;
	}
	else if (n == 0)
	{
		res[0] = '0';
		return ;
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

char	*ft_itoa(int n)
{
	char	*res;

	res = (char *)malloc((ft_nbrlen(n) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	insert(res, n);
	return (res);
}
