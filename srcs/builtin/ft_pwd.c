/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 01:05:51 by ahocine           #+#    #+#             */
/*   Updated: 2022/09/16 01:05:54 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/proto.h"

void	ft_pwd(t_lexer *lexer)
{
	char *path;
	(void)lexer;

	path = (char *)getcwd(NULL, 1000);
	if (!path || !ft_add_trash((void *)path))
		return (ft_empty_trash());
	printf("%s\n", path);
}
