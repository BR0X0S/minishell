/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headr_mo2a9at.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:18:30 by oumondad          #+#    #+#             */
/*   Updated: 2024/08/10 19:24:43 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADR_MO2A9AT_H
# define HEADR_MO2A9AT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include<readline/history.h>

typedef struct s_token
{
	int type;
	int	in_dq;
	int in_sq;
	char *str;
	struct s_token *next;
}	t_token;

typedef struct s_var
{
	int	i;
	int	x;
	int sqflag;
	int	dqflag;
	int words;
}	t_var;

t_token	*lst_last(t_token *head);
char	*ft_strdup(char *s1);
t_token	*new_node(char *str, int type, int dq, int sq);
void	token_add_back(t_token **head, t_token *new_node);

#endif