/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:18:41 by oumondad          #+#    #+#             */
/*   Updated: 2024/07/18 17:33:01 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char *get_env_name(char *str)
{
	int	i;
	char *name;
	
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	name = malloc(i + 1);
	if (!name)
		ft_error("name in get_env_name allocation faild");
	i = 0;
	while (str[i] && str[i] != '=')
	{
		name[i] = str[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}

char	*ft_envs_names(char **env)
{
	int		i;
	char	*names;
	// char	**envs_names;

	names = NULL;
	i = 0;
	while (env[i])
	{
		names = ft_strjoinn(names, get_env_name(env[i]));
		// free (get_env_name(env[i]));
		// names = ft_strjoinn(names, env[i]);
		// printf("%s\n", env[i]);
		i++;
	}
	// free(get_env_name(*env));
	// envs_names = ft_split(names, ' ');
	return (names);
}

int main(int ac, char **av, char **env)
{
	(void)ac;	
	(void)av;
	(void)env;
	char *envs_names = ft_envs_names(env);
	// char **envs_names = ft_split(av[1], '=');
	int i = 0;
	//while (envs_names[i])
	//{
		printf("%s\n", envs_names);
		i++;
	//}
	// int j = 0;
	printf("------------------>%d\n", i);
	// while (j < i)
	// {
	// 	free(envs_names[j]);
	// 	j++;
	// }
	free(envs_names);
	return (0);
}
