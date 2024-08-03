/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:46:09 by oumondad          #+#    #+#             */
/*   Updated: 2024/08/03 16:16:26 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*get_env(char **env)
{
	t_env	*head;
	t_env	*new_env;
	int		i;

	i = 0;
	head = NULL;
	while (env[i])
	{
		new_env = new_node(env[i]);
		env_add_back(&head, new_env);
		i++;
	}
	return (head);
}

void	print_env(t_env *head)
{
	while (head)
	{
		if (head->line)
			printf("%s\n", head->line);
		// printf("%s=%s\n", head->name, head->expand);
		head = head->next;
	}
}

size_t	ft_strlen_eq(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*copy;

	i = 0;
	copy = malloc(ft_strlen(s1) + 1);
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_substr(char *s, int start, size_t len)
{
	char	*place;
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (i - start < len)
		len = i - start;
	place = malloc (len + 1);
	if (!place)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		place[i] = s[start];
		i++;
		start++;
	}
	place[i] = '\0';
	return (place);
}
