/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenmot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:03:26 by caubry            #+#    #+#             */
/*   Updated: 2022/09/13 11:27:44 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_inorout(int *token, int i, char *s)
{
	*token = (int)s[i];
	if (s[i + 1] && s[i + 1] == (char)(*token))
		return (2);
	else
		return (1);
}

int	ft_lenquote(int *token, int i, char *s)
{
	int	n;

	n = 0;
	*token = (int)s[i];
	i++;
	while (s[i] && s[i] != (char)(*token))
	{
		n++;
		i++;
	}
	return (n);
}

int	ft_lenmot(char *s)
{
	int	n;
	int	token;
	int	i;

	n = 0;
	i = 0;
	token = 0;
	if (ft_strchr("><", s[i]))
		return (ft_inorout (&token, i, s));
	if (ft_strchr("'\"", s[i]))
		return (ft_lenquote (&token, i, s));
	if (s[i] == '|')
		return (1);
	while (s[i] && !ft_strchr("'\">< |", s[i]))
	{
		n++;
		i++;
	}
	return (n);
}
