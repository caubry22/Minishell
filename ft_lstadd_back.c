/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:54:34 by caubry            #+#    #+#             */
/*   Updated: 2022/09/12 15:17:54 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_lstadd_back(t_cmd **alst, t_cmd *new)
{
	t_cmd	*tmp;

	tmp = (*alst);
	// printf("new arg = %s\n", new->arg[0]);
	if (!(*alst))
	{
		printf("new list\n");
		(*alst) = new;
	}
	else
	{
		printf("la\n");
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		// new->next = NULL;
	}
	return (new);
}
