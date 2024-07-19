/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:28:58 by oumondad          #+#    #+#             */
/*   Updated: 2024/07/19 20:23:42 by oumondad         ###   ########.fr       */
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

size_t	ft_strlen1(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

t_trim	ft_strlen2(char *str)
{
	size_t	i;
	size_t	j;
	t_trim	gps;

	i = 0;
	j = 0;
	if (!str)
	{
		gps.i = 0;
		gps.j = gps.i;
		return (gps);
	}
	while (str[i] && str[i] != '=')
		i++;
	j = i + 1;
	gps.i = j;
	while (str[i])
		i++;
	gps.j = i - j;
	return (gps);
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
