/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:32:01 by caubry            #+#    #+#             */
/*   Updated: 2022/09/13 12:15:51 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int ft_exit(char **cmd, int i, int n)
// {
//     exit;
//     r
// }

// int ft_splitcmd(int i) {
//     printf("ok %d", i);
//     return(1);
// }

// t_cmd *ft_initlist()
// {
//     t_cmd *first;

//     first = NULL;
// }

int	ft_echo(char **cmd, int i, int n)
{
	if (cmd[1] && ft_strcmp(cmd[1], "-n"))
	{
		i++;
		n = 1;
	}
	while (cmd[i])
	{
		if ((i > 1 && n == 0) || i > 2)
			printf(" ");
		i++;
	}
	if (!n)
		printf("\n");
	return (1);
}

int	ft_cmd(char **cmd)
{
	if (!cmd[0])
		return (0);
	if (ft_strcmp(cmd[0], "echo"))
		ft_echo(cmd, 1, 0);
    // else if (ft_strncmp(cmd[0], "cd"))
    //     ft_cd(cmd);
    // else if (ft_strncmp(cmd[0], "pwd"))
    //     ft_pwd(cmd);
    // else if (ft_strncmp(cmd[0], "export"))
    //     ft_export(cmd);
    // else if (ft_strncmp(cmd[0], "unset"))
    //     ft_unset(cmd);
    // else if (ft_strncmp(cmd[0], "env"))
    //     ft_env(cmd);
    // else if (ft_strncmp(cmd[0], "exit"))
    //     ft_exit(cmd);
	else
		printf("Command '%s' not found\n", cmd[0]);
	return (1);
}

int	ft_erreur(int erreur)
{
	if (erreur == 1)
		printf("Il ne faut pas mettre d'arguments\n");
	return (0);
}

void	ft_printcmd(t_cmd **first)
{
	t_cmd	*lst;
	int		i;

	lst = *first;
	i = 0;
	while (lst && lst->arg[i])
	{
		while (lst->arg[i])
		{
			if (i == 0)
				printf("Nouvelle commande = ");
			printf("%s ", lst->arg[i]);
			i++;
		}
		printf("\n");
		lst = lst->next;
		i = 0;
	}
}

void	ft_initcmd(t_cmd **first, char **cmd)
{
	int	i;
	int	j;
	int	dup;

	i = 0;
	while (cmd[i])
	{
		j = 0;
		dup = i;
		while (cmd[i] && ft_strcmp(cmd[i], "|"))
		{
			i++;
			j++;
		}
		ft_lstadd_back(first, ft_lstnew(j, cmd, dup));
		j = 0;
		if (cmd[i])
			i++;
	}
}

void	ft_minishell(char *line)
{
	t_cmd	*first;
	char	**cmd;

	first = NULL;
	cmd = ft_split(line);
	if (!cmd)
		printf("Erreur de saisie\n");
	ft_initcmd(&first, cmd);
	ft_printcmd(&first);
	free(first);
}

int	main(int ac, char **av, char **envp)
{
	static char	*line;
	int		quit;
	(void)		**envp;
	int		i;

	line = NULL;
	quit = 0;
	i = 0;
	if (ac > 1 && av[0]) 
		return (ft_erreur(1));
	while (!quit)
	{
		if (line)
			free(line);
		line = readline("?>");
		if (line && *line)
		add_history(line);
		ft_minishell(line);
	}
	while (envp[i])
	{
		printf("%s\n",envp[i]);
		i++;
	}
	return (0);
}
