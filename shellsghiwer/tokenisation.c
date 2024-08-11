/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:18:38 by oumondad          #+#    #+#             */
/*   Updated: 2024/08/11 16:09:46 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headr_mo2a9at.h"
#include <string.h>

#define ERROR 404
#define WORD 1

int check_q_in_str(char *str, char c)
{
	int i;
	
	if (str[1] != '\0')
		i = 1;
	else
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_len_qoute(char *str, char c)
{
	int	i;

	i = 1;
	
	while (str[i] && str[i] != c)
		i++;
	return (i - 1);
}

char *get_word(char *str, t_var *data, char c)
{
	char	*result;
	int		j;
	int		len;

	j = 0;
	len = ft_len_qoute(&str[data->i], c);
	result = malloc (len + 1);
	while (j < len)
	{
		result[j] = str[data->i + 1 + j];
		j++;
	}
	data->i = data->i + j + 1;
	result[j] = '\0';
	return (result);
}

t_var	double_qoutes(char *str, t_var data, t_token **head)
{

	if (!check_q_in_str(&str[data.i], '"'))
		token_add_back(head, new_node("\"", ERROR, 0, 0));
	else
		token_add_back(head, new_node(get_word(str, &data, '"'), WORD, 1, 0));
	return (data);
}

t_var	single_qoutes(char *str, t_var data, t_token **head)
{
	if (!check_q_in_str(&str[data.i], '\''))
		token_add_back(head, new_node("'", ERROR, 0, 0));
	else
		token_add_back(head, new_node(get_word(str, &data, '\''), WORD, 0, 1));
	return (data);
}

t_token	*ft_tokenisation(char *str)
{
	t_var data;
	t_token *head;
	
	head = NULL;
	data.i = 0;
	
	while (str[data.i])
	{
		
		if (str[data.i] != ' ' && str[data.i] != '\t')
		{
			if (str[data.i] == '"')
				data = double_qoutes(str, data, &head);
			else if (str[data.i] == '\'')
				data = single_qoutes(str, data, &head);
			// else if (!check_special_char(str, data.i))
			// 	data = handle_special_char(str, data, &head);
			// else
			// 	data = set_word(str, data);
		}
		data.i++;
	}
	return (head);
}

int main (int ac, char **av)
{
	// char *str;
	// while (1337)
	// {
	// 	str = readline("cont word: ");
	// 	if (!str)
	// 		break;
	// 	add_history(str);
	// 	printf("Number of words ->%d\n", count_word(str, ' '));
	// 	free(str);
	// }
	t_token *head = ft_tokenisation("'vjhksdbz $USER $USER'  | pwd | echo $USER");
	while (head)
	{
		printf("type = |%d|\n", head->type);
		printf("in_dq= |%d|\n", head->in_dq);
		printf("in_sq= |%d|\n", head->in_sq);
		printf("word = |%s|\n", head->str);
		printf("================\n");
		// free(head->str);
		head = head->next;
	}
	exit (0);
}
