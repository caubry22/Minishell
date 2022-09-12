/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 23:21:02 by caubry            #+#    #+#             */
/*   Updated: 2021/01/04 18:45:30 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strsize(char const *str)
{
	size_t n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

static char		*ft_dup(char *dst, char const *src, size_t k)
{
	while (*src)
	{
		dst[k] = *src;
		src++;
		k++;
	}
	return (dst);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	s1len;
	size_t	s2len;
	size_t	jlen;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strsize(s1);
	s2len = ft_strsize(s2);
	jlen = 0;
	if (!(join = (char *)malloc(sizeof(char) * (s1len + s2len + 1))))
		return (NULL);
	ft_dup(join, s1, jlen);
	jlen = jlen + s1len;
	ft_dup(join, s2, jlen);
	jlen = jlen + s2len;
	join[jlen] = 0;
	return (join);
}
