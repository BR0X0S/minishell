/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:33:17 by oumondad          #+#    #+#             */
/*   Updated: 2024/08/10 20:17:05 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headr_mo2a9at.h"
#include <string.h>

t_token	*lst_last(t_token *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head -> next;
	return (head);
}

t_token	*new_node(char *str, int type, int dq, int sq)
{
	t_token	*new_node;

	new_node = malloc(sizeof(t_token));
	if (!new_node)
		printf("ERROR: new_node malloc failed!\n");
	new_node->type = type;
	new_node->in_dq = dq;	
	new_node->in_sq = sq;
	new_node->str = str;
	new_node->next = NULL;
	return (new_node);
}

void	token_add_back(t_token **head, t_token *new_node)
{
	t_token	*last_node;

	if (!head)
		return ;
	last_node = lst_last(*head);
	if (*head)
		last_node->next = new_node;
	else
		*head = new_node;
}

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return (i);
}
char	*ft_strdup(char *s1)
{
	int		i;
	char	*copy;

	i = 0;
	copy = malloc(ft_strlen(s1) + 1);
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
