/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:22:37 by oumondad          #+#    #+#             */
/*   Updated: 2024/08/12 19:22:42 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_len_quote(char *str, char c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (1)
	{
		while (str[i] && str[i] != c)
			i++;
		if (str[i] == c)
			flag = on_off(flag);
		if (flag == 0 && (str[i] == '\0' || str[i + 1] == '\0'
			|| is_ws(str[i + 1]) || is_sc(str[i + 1])))
			return (i + 1);
		i++;
	}
	return (-1);
}
