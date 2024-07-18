/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:28:40 by oumondad          #+#    #+#             */
/*   Updated: 2024/07/18 17:32:47 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINISHELL_H
# define MINISHELL_H

/*HIDERz*/

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>


/*lINKDLIST  */

typedef struct	s_env
{
	char			*name;
	char			**expand;
	struct s_env	*next;
}	t_env;

typedef struct	s_collect
{
	char	**names;
}	t_collet;

void	ft_error(char *str);
size_t	ft_strlen(char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoinn(char *stack, char *buffer);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif