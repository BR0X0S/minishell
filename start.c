/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:18:41 by oumondad          #+#    #+#             */
/*   Updated: 2024/07/27 11:01:36 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *str1, char *str2)
{
	int		i;

	i = 0;
	while ((str1[i] == str2[i]) && (str1[i] || str2[i]))
		i++;
	if (str1[i] == str2[i])
		return (0);
	else
		return (1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (fd, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	nsit_smiya(char **env, char *str, int fd)
{
	char	**names;
	char	**expand;
	int		i;

	i = 0;
	names = get_envs_names(env);
	expand = get_envs_expand(env);
	while (env[i])
	{
		if (ft_strcmp(names[i], &str[1]) == 0)
			ft_putstr_fd(expand[i], fd);
		free(names[i]);
		free(expand[i]);
		i++;
	}
	while (env[i])
	{
		free(names[i]);
		free(expand[i]);
	}
	free(names);
	free(expand);
}
