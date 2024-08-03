/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:28:40 by oumondad          #+#    #+#             */
/*   Updated: 2024/08/03 16:14:39 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*-- LIBRARIES --*/

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/*--- STRUCTS ---*/

typedef struct s_env
{
	char			*line;
	char			*name;
	char			*expand;
	struct s_env	*next;
}	t_env;

// typedef struct s_all
// {
// 	t_env	*head;
// 	char	**path;
// }	t_all;

// extern int	g_signal;

/*-- FUNCTIONS --*/

size_t	ft_strlen(char *str);
size_t	ft_strlen_eq(char *str);
void	ft_error(char *str);
int		ft_strcmp(char *str1, char *str2);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, int start, size_t len);
t_env	*get_env(char **env);
t_env	*new_node(char *line);
void	env_add_back(t_env **head, t_env *new_node);
void	print_env(t_env *head);
void	ft_lstclear(t_env **lst);

#endif