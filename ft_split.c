/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:31:49 by caubry            #+#    #+#             */
/*   Updated: 2022/09/14 15:05:21 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_nbmot(char *s, char c)
{
	int	nbmot;

	nbmot = 0;
	while (*s)
	{
		if (*s != c)
		{
			nbmot++;
			while (*s != c && *s)
				s++;
		}
		while (*s == c && *s)
			s++;
	}
	return (nbmot);
}

char	*ft_fillsplitcmd(char *mot, char *str, char c)
{
	int	i;

	i = 0;
	while (*str && *str != c)
	{
		mot[i] = *str;
		i++;
		str++;
	}
	mot[i] = 0;
	return (mot);
}

int	ft_lenmotcmd(char *s, char c)
{
	int	n;

	n = 0;
	while (*s && *s != c)
	{
		n++;
		s++;
	}
	return (n);
}

char	**ft_splitboucle(char *str, char **split, char c)
{
	int k;
	int	len;

	k = 0;
	while (*str && k < 7)
	{
		while (*str == c && *str)
			str++;
		len = ft_lenmotcmd(str, c);
		split[k] = (char *)malloc(sizeof(char) * (len + 1));
		if (!split[k])
			return (ft_free(split));
		split[k] = ft_fillsplitcmd(split[k], str, c);
		str = str + len;
		k++;
	}
	split[k] = NULL;
	return(split);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**split;

	str = (char *)s;
	if (!str)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * 8);
	if (!split)
		return (NULL);
	return (ft_splitboucle(str, split, c));
}
