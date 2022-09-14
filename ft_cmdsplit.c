/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:07:20 by caubry            #+#    #+#             */
/*   Updated: 2022/09/14 12:06:38 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_len(const char *s)
{
	int	t;

	t = 0;
	while (*s)
	{
		t++;
		s++;
	}
	return (t);
}

char	*ft_strchr(const char *s, int c)
{
	int				size;
	unsigned char	a;

	size = ft_len(s);
	a = (unsigned char)c;
	s = s + size;
	while (size >= 0)
	{
		if (*s == a)
			return ((char *)s);
		s--;
		size--;
	}
	return (NULL);
}

char	*ft_fillsplit(char *mot, char *str, int len)
{
	int	i;

	i = 0;
	if (ft_strchr("'\"", *str))
		str++;
	while (*str && len)
	{
		mot[i] = *str;
		i++;
		len--;
		str++;
	}
	mot[i] = 0;
	return (mot);
}

char	**ft_algosplit(char *str, char **split, int mot)
{
	int	k;
	int	len;

	k = 0;
	while (*str && k < mot)
	{
		while ((*str == ' ' || *str == 11) && *str)
			str++;
		len = ft_lenmot(str);
		split[k] = (char *)malloc(sizeof(char) * (len + 1));
		if (!split[k])
			return (ft_free(split));
		split[k] = ft_fillsplit(split[k], str, len);
		if (ft_strchr("'\"", *str))
			len = len + 2;
		str = str + len;
		k++;
	}
	split[k] = NULL;
	return (split);
}

char	**ft_cmdsplit(char const *s)
{
	char	*str;
	char	**split;
	int		mot;

	str = (char *)s;
	if (!str)
		return (NULL);
	mot = ft_nbtoken(str);
	if (mot < 0)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (mot + 1));
	if (!split)
		return (NULL);
	return (ft_algosplit(str, split, mot));
}
