/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:14:23 by caubry            #+#    #+#             */
/*   Updated: 2022/09/12 10:25:25 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*a;
	unsigned char	*b;
	int i;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (a[i] && a[i] == b[i])
		i++;
	return (a[i] - b[i]);
}
