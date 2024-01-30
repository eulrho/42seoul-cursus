/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:28:44 by erho              #+#    #+#             */
/*   Updated: 2024/01/24 21:30:30 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	make_word(char *s1, char *s2, t_command *cmd)
{
	int	s1_idx;
	int	s2_idx;

	s1_idx = 0;
	s2_idx = 0;
	while (s1_idx < cmd->len)
	{
		if (check_quote(s2, s2_idx))
		{
			cmd->quotes = s2[s2_idx++];
			while (s2[s2_idx] && (s2[s2_idx] != cmd->quotes
					|| !check_quote(s2, s2_idx)))
			{
				if (!check_slash(s2, s2_idx))
					s1[s1_idx++] = s2[s2_idx];
				s2_idx++;
			}
		}
		else if (!check_slash(s2, s2_idx))
			s1[s1_idx++] = s2[s2_idx];
		s2_idx++;
	}
}

void	find_idx(t_command *cmd, char *s, char c)
{
	while (s[cmd->hor_idx] && s[cmd->hor_idx] == c)
		cmd->hor_idx++;
	if (s[cmd->hor_idx])
		cmd->word_count++;
	cmd->word = cmd->hor_idx;
	while (s[cmd->hor_idx] && s[cmd->hor_idx] != c)
	{
		if (check_quote(s, cmd->hor_idx))
		{
			cmd->quotes = s[cmd->hor_idx];
			cmd->hor_idx++;
			while (s[cmd->hor_idx] && (s[cmd->hor_idx] != cmd->quotes
					|| !check_quote(s, cmd->hor_idx)))
			{
				cmd->hor_idx++;
				if (!check_slash(s, cmd->hor_idx))
					cmd->len++;
			}
		}
		else if (!check_slash(s, cmd->hor_idx))
			cmd->len++;
		if (s[cmd->hor_idx])
			cmd->hor_idx++;
	}
}

char	**ft_insert(char *s, char **res, char c, t_command cmd)
{
	while (s[cmd.hor_idx])
	{
		cmd.len = 0;
		find_idx(&cmd, s, c);
		if (cmd.hor_idx > cmd.word)
		{
			res[cmd.ver_idx] = (char *)malloc(sizeof(char) * (cmd.len + 1));
			if (res[cmd.ver_idx] == NULL)
				print_error(NULLGUARD);
			make_word(res[cmd.ver_idx], &s[cmd.word], &cmd);
			res[cmd.ver_idx][cmd.len] = '\0';
			cmd.ver_idx++;
		}
	}
	return (res);
}

int	count_word(char *s, char c, t_command cmd)
{
	while (s[cmd.hor_idx])
		find_idx(&cmd, s, c);
	return (cmd.word_count);
}

char	**parsing_command(char *s, char c)
{
	int			cnt;
	char		**res;
	t_command	cmd;

	cmd.hor_idx = 0;
	cmd.ver_idx = 0;
	cmd.word_count = 0;
	cmd.len = 0;
	cnt = count_word(s, c, cmd);
	res = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (res == NULL)
		print_error(NULLGUARD);
	res = ft_insert(s, res, c, cmd);
	if (res != NULL)
		res[cnt] = NULL;
	return (res);
}
