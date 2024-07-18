/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tansemih_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:46:09 by oumondad          #+#    #+#             */
/*   Updated: 2024/07/18 14:17:46 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstsize(t_env *lst)
{
	int	i;

	i = 0;
	while (lst->next)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_env	*lst_last(t_env	*head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head -> next;
	return (head);
}

t_env	*env_add_back(t_env *head, char *name, char	**expand)
{
	
}
