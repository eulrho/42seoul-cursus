/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:57:00 by erho              #+#    #+#             */
/*   Updated: 2023/10/10 20:16:56 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

void	make_word(char *s1, char const *s2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

int	count_word(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			cnt++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (cnt);
}

char	**ft_insert(char const *s, char **res, char c)
{
	int	i;
	int	word;
	int	array;

	i = 0;
	array = 0;
	while (s[i])
	{	
		while (s[i] && s[i] == c)
			i++;
		word = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > word)
		{
			res[array] = (char *)malloc(sizeof(char) * (i - word + 1));
			if (res[array] == NULL)
				return (ft_free(res));
			make_word(res[array], &s[word], i - word);
			array++;
		}
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		cnt;
	char	**res;

	cnt = count_word(s, c);
	res = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (res == NULL)
		return (NULL);
	res = ft_insert(s, res, c);
	if (res != NULL)
		res[cnt] = NULL;
	return (res);
}
