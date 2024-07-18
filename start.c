/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:18:41 by oumondad          #+#    #+#             */
/*   Updated: 2024/07/18 21:43:59 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_envs_names(char **env)
{
	int		i;
	char	*names;
	char	**envs_names;

	names = NULL;
	i = 0;
	while (env[i])
	{
		names = ft_strjoin1(names, env[i]);
		i++;
	}
	envs_names = ft_split(names, ' ');
	free(names);
	return (envs_names);
}

char	**get_envs_expand(char **env)
{
	int		i;
	char	*joined_expands;
	char	**splited_expands;

	joined_expands = NULL;
	i = 0;
	while (env[i])
	{
		joined_expands = ft_strjoin2(joined_expands, env[i]);
		i++;
	}
	splited_expands = ft_split(joined_expands, '\n');
	free(joined_expands);
	return (splited_expands);
}

// int main(int ac, char **av, char **env)
// {
// 	(void)ac;	
// 	(void)av;
// 	(void)env;
// 	char **envs_names = get_envs_names(env);
// 	int i = 0;
// 	while (envs_names[i])
// 	{
// 		printf("%s\n", envs_names[i]);
// 		i++;
// 	}
// 	int j = 0;
// 	printf("------------------>%d\n", i);
// 	while (j <= i)
// 	{
// 		free(envs_names[j]);
// 		j++;
// 	}
// 	free(envs_names);
// 	return (0);
// }


// int main(int ac, char **av, char **env)
// {
// 	(void)ac;	
// 	(void)av;
// 	(void)env;
// 	t_trim	gps = ft_strlen2(env[0]);
// 	printf("mnin ghanbda  ->%zu\n", gps.i);
// 	printf("fin ghanssali ->%zu\n", gps.j);
// 	return (0);
// }

// int main(int ac, char **av, char **env)
// {
// 	(void)ac;	
// 	(void)av;
// 	(void)env;
// 	char **names;
// 	char **expands;
// 	names = get_envs_names(env);
// 	expands = get_envs_expand(env);
// 	int	i = 0;
// 	while (env[i])
// 	{
// 		printf("🦁Name ->%s", names[i]);
// 		printf("🐐Expand ->%s\n", expands[i]);
// 		i++;
// 	}
// 	int j = 0;
// 	while (j <= i)
// 	{
// 		free(names[j]);
// 		j++;
// 	}
// 	free(names);
// 	j = 0;
// 	while (j <= i)
// 	{
// 		free(expands[j]);
// 		j++;
// 	}
// 	free(expands);
// 	return (0);
// }
