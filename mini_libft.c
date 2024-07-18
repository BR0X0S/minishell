/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:28:58 by oumondad          #+#    #+#             */
/*   Updated: 2024/07/18 16:47:07 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_error(char *str)
{
	write (1, str, ft_strlen(str));
	exit (1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*place;
	size_t	i;

	place = malloc (len + 1);
	if (!place)
		ft_error ("Error : substr allocation faild");
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

char	*ft_strjoinn(char *stack, char *buffer)
{
	char	*str;
	size_t	j;
	size_t	i;
	size_t	stack_len;
	size_t	buffer_len;

	stack_len = ft_strlen(stack);
	buffer_len = ft_strlen(buffer);
	i = -1;
	str = malloc(stack_len + buffer_len + 2);
	if (!str)
		ft_error("strjoinn allocation faild");
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
