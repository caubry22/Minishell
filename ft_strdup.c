/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:13:01 by caubry            #+#    #+#             */
/*   Updated: 2022/09/13 10:16:16 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_len(char *s1)
{
	int	len;

	len = 0;
	while (*s1)
	{
		len++;
		s1++;
	}
	return (len);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*dup;
	char	*c1;

	i = 0;
	c1 = (char *)s1;
	len = ft_len(c1);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (*c1)
	{
		dup[i] = *c1;
		c1++;
		i++;
	}
	dup[i] = 0;
	return (dup);
}
