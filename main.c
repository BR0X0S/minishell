/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:44:19 by oumondad          #+#    #+#             */
/*   Updated: 2024/07/27 11:00:39 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_env	*head;

	(void)ac;
	(void)av;
	(void)env;
	head = get_env(env);
	// print_env(env);
	// printf("%d\n", ft_strcmp(av[1], av[2]));
	nsit_smiya(env, av[1], 1);
	// expand_env(av[1]);
	// printf("%s\n", av[1]);
	exit (0);
}
