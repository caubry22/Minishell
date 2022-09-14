/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbtoken.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:03:44 by caubry            #+#    #+#             */
/*   Updated: 2022/09/14 16:02:36 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_quote(char *s, int *quote, int *nbtoken)
{
	if (ft_strchr("'\"", *s))
	{
		(*nbtoken)++;
		(*quote) = (int)*s;
		s++;
		while (*s != (char)(*quote) && *s)
		{
			s++;
		}
		if (*s)
		{
			(*quote) = 0;
			s++;
		}
	}
	return (s);
}

char	*ft_redirection(char *s, int *quote, int *nbtoken)
{
	if (ft_strchr("<>", *s) && *s)
	{
		(*nbtoken)++;
		*quote = (int)*s;
		s++;
		if ((int)*s == (*quote))
			s++;
		*quote = 0;
	}
	return (s);
}

char	*ft_sepcmd(char *s, int *nbtoken)
{
	if (*s && !ft_strchr("\"'| <>", *s))
	{
		(*nbtoken)++;
		while (!ft_strchr("\"'| <>", *s))
			s++;
	}
	return (s);
}

char	*ft_space(char *s, int *nbtoken)
{
	if (*s && ft_strchr(" ", *s))
	{
		(*nbtoken)++;
		while (*s && ft_strchr(" ", *s))
			s++;
	}
	return (s);
}


int	ft_nbtoken(char *s)
{
	int	nbtoken;
	int	quote;

	nbtoken = 0;
	quote = 0;
	while (*s)
	{
		while (*s && (*s == ' ' || *s == 11))
			s++;
		s = ft_quote(s, &quote, &nbtoken);
		if (*s && *s == '|')
		{
			nbtoken++;
			s++;
		}
		s = ft_redirection(s, &quote, &nbtoken);
		s = ft_sepcmd(s, &nbtoken);
		s = ft_space(s, &nbtoken);
	}
	if (quote != 0)
		return (-1);
	return (nbtoken);
}
