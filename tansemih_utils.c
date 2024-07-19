/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tansemih_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:46:09 by oumondad          #+#    #+#             */
/*   Updated: 2024/07/19 16:26:55 by oumondad         ###   ########.fr       */
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

t_env	*new_node(char *name, char	*expand)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		ft_error("new_node allocation faild");
	new_node->name = name;
	new_node->expand = ft_split(expand, ':');
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

t_env	*get_env(char **env)
{
	t_env	*head;
	t_env	*new_env;
	int		j;
	char	**name;
	char	**expand;

	j = 0;
	head = NULL;
	name = get_envs_names(env);
	expand = get_envs_expand(env);
	while (env[j])
	{
		new_env = new_node(name[j], expand[j]);
		env_add_back(&head, new_env);
		j++;
	}
	return (head);
}

void	print_env(t_env *head)
{
	int	i;
	while (head)
	{
		i = 0;
		printf("name=%s\nexpand -> ", head->name);
		while (head->expand[i])
		{
			printf("%s:", head->expand[i]);
			i++;
		}
		printf("\n");
		head = head->next;
	}
}
