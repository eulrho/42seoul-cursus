/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:24:00 by erho              #+#    #+#             */
/*   Updated: 2023/10/10 20:22:25 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_set(char const s1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	total_len(char const *s1, char const *set, size_t *start, size_t *end)
{
	int	i;

	i = 0;
	if (s1[0] == '\0')
		return (0);
	while (s1[i] && check_set(s1[i], set) == 1)
		i++;
	*start = (size_t)i;
	i = ft_strlen(s1) - 1;
	if (i < 0)
		i = 0;
	while (i > -1 && (s1[i] && check_set(s1[i], set) == 1))
		i--;
	*end = (size_t)i + 1;
	if (*start > *end)
		return (0);
	return (*end - *start);
}

static void	insert_str(char *res, char const *s1, size_t start, size_t end)
{
	size_t	i;

	i = start;
	while (i < end)
	{	
		res[i - start] = s1[i];
		i++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	len;
	size_t	start;
	size_t	end;

	len = total_len(s1, set, &start, &end);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	if (len > 0)
		insert_str(res, s1, start, end);
	res[len] = '\0';
	return (res);
}

