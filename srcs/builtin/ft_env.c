/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:00:08 by ahocine           #+#    #+#             */
/*   Updated: 2022/09/14 22:00:09 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/proto.h"

void	ft_env(t_lexer *lexer)
{
	t_env **env;
	t_env *tmp;
	(void)lexer;

	env = ft_get_env();
	tmp = *env;
	while (tmp)
	{
		printf("%s\n", tmp->env_name);
		tmp = tmp->next;
	}
	// VOIR POUR LA VARIABLE $SHLVL
}
