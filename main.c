/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:44:19 by oumondad          #+#    #+#             */
/*   Updated: 2024/07/19 00:51:12 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
	(void)ac;	
	(void)av;
	(void)env;
	t_env	*head;
	t_env	*new_env;
	head = NULL;
	int i = 0;
	while (env[i])
		i++;
	int j = 0;
	char **name = get_envs_names(env);
	char **expand = get_envs_expand(env);
	
	while (j < i)
	{
		new_env = new_node(name[j], expand[j]);
		env_add_back(&head, new_env);
		printf("name  ->%s\n", name[j]);
		printf("expand  ->%s\n", expand[j]);
		j++;
	}
	printf("name  ->%s\n", head->name);
	printf("expand ->%s\n", head->expand[0]);
	return (0);
}