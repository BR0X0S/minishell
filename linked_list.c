/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:33:17 by oumondad          #+#    #+#             */
/*   Updated: 2024/08/03 16:12:27 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*lst_last(t_env	*head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head -> next;
	return (head);
}

t_env	*new_node(char *line)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		ft_error("ERROR: new_node malloc failed!\n");
	new_node->line = ft_strdup(line);
	new_node->name = ft_substr(line, 0, ft_strlen_eq(line));
	new_node->expand = ft_substr(line, ft_strlen_eq(line) + 1, ft_strlen(line));
	new_node->next = NULL;
	return (new_node);
}

void	env_add_back(t_env **head, t_env *new_node)
{
	t_env	*last_node;

	if (!head)
		return ;
	last_node = lst_last(*head);
	if (*head)
		last_node->next = new_node;
	else
		*head = new_node;
}

void	ft_lstclear(t_env **lst)
{
	t_env	*tmp;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		tmp = *lst;
		free((*lst)->line);
		free((*lst)->name);
		free((*lst)->expand);
		*lst = (*lst)-> next;
		free (tmp);
	}
	tmp = NULL;
}
