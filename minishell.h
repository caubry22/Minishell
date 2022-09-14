/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:23:42 by caubry            #+#    #+#             */
/*   Updated: 2022/09/14 14:52:46 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_cmd
{
    int token;
    int option;
    char **arg;
    struct s_cmd *next;
}       t_cmd;

char	**ft_cmdsplit(char const *s);
int	ft_strcmp(const char *s1, const char *s2);
int ft_nbtoken(char *s);
t_cmd	*ft_lstnew(int j, char **cmd, int dup);
t_cmd *ft_lstadd_back(t_cmd **alst, t_cmd *new);
char		*ft_strdup(const char *s1);
int	ft_nbtoken(char *s);
int	ft_lenmot(char *s);
char		*ft_strchr(const char *s, int c);
char	**ft_free(char **split);
int ft_isbuiltin(char *word);
char	**ft_split(char const *s, char c);

#endif