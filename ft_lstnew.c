/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:18:53 by caubry            #+#    #+#             */
/*   Updated: 2022/09/12 15:52:23 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_lstnew(int j, char **cmd, int dup)
{
	t_cmd	*list;
	int i;

	i = 0;
	if (!(list = malloc(sizeof(t_cmd))))
		return (NULL);
	list->arg = malloc(sizeof(char *) * (j + 1));
	if (!list->arg)
		return (NULL);
	while (i < j && cmd[dup + i])
	{
		// printf("arg[i] %s\n", cmd[dup + i]);
		// printf("cmd[dup + i] %s\n", cmd[dup + i]);
		list->arg[i] = ft_strdup(cmd[dup + i]);
		i++;
	}
	list->arg[i] = NULL;
	list->token = 0;
	list->option = 0;
	list->next = NULL;
	return (list);
}