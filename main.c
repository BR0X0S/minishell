/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:44:19 by oumondad          #+#    #+#             */
/*   Updated: 2024/07/19 16:23:00 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
	(void)ac;	
	(void)av;
	(void)env;
	t_env	*head = get_env(env);
	print_env(head);
	
	// t_env	*new_env;
	// head = NULL;
	// int i = 0;
	// char **name = get_envs_names(env);
	// char **expand = get_envs_expand(env);
	
	// while (env[j])
	// {
	// 	new_env = new_node(name[j], expand[j]);
	// 	env_add_back(&head, new_env);
	// 	j++;
	// }
	// while (head)
	// {
	// 	i = 0;
	// 	printf("name  ->%s\nexpand -> ", head->name);
	// 	while (head->expand[i])
	// 	{
	// 		printf("%s ", head->expand[i]);
	// 		i++;
	// 	}
	// 	printf("\n");
	// 	head = head->next;
	// }
	// return (0);
}