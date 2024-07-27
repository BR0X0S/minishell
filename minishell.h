/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:28:40 by oumondad          #+#    #+#             */
/*   Updated: 2024/07/27 11:03:06 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*HIDERz*/

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/*lINKDLIST  */

typedef struct s_env
{
	char			*name;
	char			**expand;
	struct s_env	*next;
}	t_env;

typedef struct s_all
{
	t_env	*head;
}	t_all;

typedef struct s_trim
{
	size_t	i; /*i = mnin khassni nbda*/
	size_t	j; /*j = lent dyal expand*/
}	t_trim;

/*fonksyonat dyal lpars dyal environmon*/

int		ft_strcmp(char *str1, char *str2);
void	nsit_smiya(char **env, char *str, int fd);
void	ft_error(char *str);
t_env	*get_env(char **env);
size_t	ft_strlen(char *str);
size_t	ft_strlen1(char *str);
t_trim	ft_strlen2(char *str);
void	print_env(char **env);
void	print_struct(t_env *head);
char	**get_envs_names(char **env);
char	**get_envs_expand(char **env);
char	**ft_split(char const *s, char c);
t_env	*new_node(char *name, char	*expand);
char	*ft_strjoin1(char *stack, char *buffer);
char	*ft_strjoin2(char *stack, char *buffer);
void	env_add_back(t_env **head, t_env *new_node);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*ghn3ddbk akhay hamza*/

#endif