/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:31:00 by erho              #+#    #+#             */
/*   Updated: 2024/01/20 16:09:05 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	check_slash(char *s, int target)
{
	int	back;

	back = target + 1;
	if (s[target] == '\\' && (s[back] && is_quote(s, back)))
		return (1);
	return (0);
}

int	is_with_slash(char *s, int target)
{
	int	front;

	front = target - 1;
	if (front >= 0 && s[front] == '\\')
		return (1);
	return (0);
}

int	is_quote(char *s, int target)
{
	if (s[target] != 34 && s[target] != 39)
		return (0);
	return (1);
}

int	check_quote(char *s, int target)
{
	if (!is_quote(s, target) || is_with_slash(s, target))
		return (0);
	return (1);
}
