/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_pars_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:27:37 by oumondad          #+#    #+#             */
/*   Updated: 2024/07/27 11:02:32 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin1(char *stack, char *buffer)
{
	char	*str;
	size_t	j;
	size_t	i;
	size_t	stack_len;
	size_t	buffer_len;

	stack_len = ft_strlen1(stack);
	buffer_len = ft_strlen1(buffer);
	i = -1;
	str = malloc(stack_len + buffer_len + 2);
	if (!str)
		ft_error("strjoin1 allocation faild");
	while (++i < stack_len && stack)
		str[i] = stack[i];
	str[i] = '\0';
	j = -1;
	while (++j < buffer_len)
		str[i + j] = buffer[j];
	str[i + j] = ' ';
	str[i + j + 1] = '\0';
	return (free (stack), str);
}

char	*ft_strjoin2(char *stack, char *buffer)
{
	char	*str;
	size_t	j;
	size_t	i;
	size_t	stack_len;
	t_trim	buffer_len;

	stack_len = ft_strlen(stack);
	buffer_len = ft_strlen2(buffer);
	i = -1;
	str = malloc(stack_len + buffer_len.j + 2);
	if (!str)
		ft_error("strjoin2 allocation faild");
	while (++i < stack_len && stack)
		str[i] = stack[i];
	str[i] = '\0';
	j = -1;
	while (++j < buffer_len.j)
	{
		str[i + j] = buffer[buffer_len.i];
		buffer_len.i++;
	}
	str[i + j] = '\n';
	str[i + j + 1] = '\0';
	return (free (stack), str);
}

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

void	print_struct(t_env *head)
{
	int	i;

	while (head)
	{
		i = 0;
		printf("%s=", head->name);
		while (head->expand[i])
		{
			printf("%s", head->expand[i]);
			i++;
			if (head->expand[i])
				printf(":");
		}
		printf("\n");
		head = head->next;
	}
}

void	print_env(char **env)
{
	char	**names;
	char	**expand;
	int		i;

	i = 0;
	names = get_envs_names(env);
	expand = get_envs_expand(env);
	while (env[i])
	{
		printf("%s=", names[i]);
		printf("%s\n", expand[i]);
		free(names[i]);
		free(expand[i]);
		i++;
	}
	free(names);
	free(expand);
}
