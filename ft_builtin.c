/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:35:28 by caubry            #+#    #+#             */
/*   Updated: 2022/09/14 12:32:54 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isbuiltin(char *word)
{
	char	**builtin;
	int		i;

	i = 0;
	builtin = ft_split("echo cd pwd export unset env exit", ' ');
	while (i < 7)
	{
		if (!ft_strcmp(word, builtin[i]))
			return (i);
		i++;
	}
	return (0);
}
