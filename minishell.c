/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:32:01 by caubry            #+#    #+#             */
/*   Updated: 2022/09/12 16:09:45 by caubry           ###   ########.fr       */
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

int ft_echo(char **cmd, int i, int n)
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
        // printf("%s", cmd[i]);
        i++;
    }
    if (!n)
        printf("\n");
    return (1);
}

int ft_cmd(char **cmd)
{
    if (!cmd[0])
        return(0);
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
    return(1);
}

int main(int ac, char **av, char **envp)
{
    static char *line;
    char **cmd;
    int quit;
    (void)**envp;
    int i;
    int j;
    int a;
    t_cmd *first;
    t_cmd *new;
    int dup;

    line = NULL;
    quit = 0;
    i = 0;
    if (ac > 1 && av[0]) 
    {
        printf("Il ne faut pas mettre d'arguments\n");
        return (0);
    }
    while (!quit)
    {
        first = NULL;
        i = 0;
        if (line)
            free(line);
        line = readline("?>");
        if (line && *line)
            add_history(line);
        cmd = ft_split(line);
        if (!cmd)
            printf("Erreur de saisie\n");
        while (cmd[i])
        {
            j = 0;
            dup = i;
            // printf("dup = %d\n", dup);
            while (cmd[i] && ft_strcmp(cmd[i], "|"))
            {
                // printf("ICI????\n");
                i++;
                j++;
            }
            new = ft_lstadd_back(&first, ft_lstnew(j, cmd, dup));
            // printf("first arg = %s\n", first->arg[0]);
            j = 0;
            // printf("cmd[dup] = %s\n", cmd[dup]);
            printf("new->arg[%d] = %s\n", j, new->arg[0]);
            // printf("cmd[i] avant = %s\n", cmd[i]);
            if (cmd[i])
                i++;
            // printf("cmd[i] apres = %s\n", cmd[i]);
        }
        // test = ft_lstnew(cmd);
        a = 0;
        while (first && first->arg[a])
        {
            while (first->arg[a])
            {
                printf("FIN = %s ", first->arg[a]);
                a++;
            }
            // i = 0;
            // first = first->next;
            // printf("testcrassh\n");
            printf("\n");
            a = 0;
            first = first->next;
        }
        // printf("FINFIN = %s ", first->next->arg[0]);
        free(first);
        printf("\n");
        // ft_cmd(cmd);
        // printf("nombre de token %d\n", ft_nbtoken(line));
    }
    i = 0;
    while (envp[i])
    {
        printf("%s\n",envp[i]);
        i++;
    }
    return (0);
}
