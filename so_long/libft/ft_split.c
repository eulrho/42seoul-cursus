/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:00:21 by erho              #+#    #+#             */
/*   Updated: 2023/12/11 14:39:03 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	make_word(char *s1, char const *s2, int n)
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

static int	count_word(char const *s, char c)
{
	int	i;
	int	cnt;
	int	next_line;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		next_line = 0;
		while (s[i + next_line] && s[i + next_line] == c)
			next_line++;
		if (next_line >= 2)
			print_error(INVALID_MAP);
		else
			i += next_line;
		if (s[i])
			cnt++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (cnt);
}

static char	**ft_insert(char const *s, char **res, char c)
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
				print_error(MEMORY);
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
		print_error(MEMORY);
	res = ft_insert(s, res, c);
	if (res != NULL)
		res[cnt] = NULL;
	return (res);
}
