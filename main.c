/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:44:19 by oumondad          #+#    #+#             */
/*   Updated: 2024/07/18 21:53:33 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
	(void)ac;	
	(void)av;
	(void)env;
	t_env	*head;
	head = malloc(sizeof(t_env));
	int i = 0;
	while (env[i])
		i++;
	int j = 0;
	char **name = get...;
	while (j < i)
	{
		new_node()
		env_add_back(&head, )
	}
	printf("mnin ghanbda  ->%zu\n", gps.i);
	printf("fin ghanssali ->%zu\n", gps.j);
	return (0);
}