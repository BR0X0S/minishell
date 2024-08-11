/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:18:38 by oumondad          #+#    #+#             */
/*   Updated: 2024/08/11 20:05:49 by oumondad         ###   ########.fr       */
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

int	ft_len_qoute(char *str, char c, int i, int flag)
{
	if (str[i] == c && flag == 1)
		flag = 0;
	i++;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] != '\0' && str[i + 1] != '\0' && str[i + 1] != ' ' && str[i + 1] != '\t')
	{
		i = ft_len_qoute(str, c, i, 1);
		i++;
	}
	if ((str[i] == '\0' || str[i] == ' ' || str[i] != '\t') && flag == 0)
		return (i - 1);
	return (-1);
}

int	check_str(char *str, char c)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	// dq = 0;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i - 1] != c)
			q++;
		printf("hada -> %c\n", c);
		i++;
	}
	i--;
	while (i > 0 && str[i] != c)
		i--;
	if (q % 2 != 0)
		return (0);
	return (1);
}

char *get_word(char *str, t_var *data, char c)
{
	char	*result;
	int		j;
	int		len;

	j = 0;
	len = ft_len_qoute(&str[data->i], c, 1, 0);
	// if (len == -1 || !check_str(&str[data->i], c))
	if (len == -1)
	{
		result = "Error";
		return (result);
	}
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
	{
		token_add_back(head, new_node("\"", ERROR, 0, 0));
	}
	else
	{
		if (str[data.i + 1] && str[data.i + 1] == '"')
		{
			token_add_back(head, new_node('\0', WORD, 1, 0));
			data.i++;
			return (data);
		}
		token_add_back(head, new_node(get_word(str, &data, '"'), WORD, 1, 0));
	}
	return (data);
}

t_var	single_qoutes(char *str, t_var data, t_token **head)
{
	if (check_q_in_str(&str[data.i], '\'') == 0)
		token_add_back(head, new_node("'", ERROR, 0, 0));
	else
	{
		if (str[data.i + 1] && str[data.i + 1] == '\'')
		{
			token_add_back(head, new_node('\0', WORD, 0, 1));
			data.i++;
			return (data);
		}
		token_add_back(head, new_node(get_word(str, &data, '\''), WORD, 0, 1));
	}
	return (data);
}

int	special_characters(char c)
{
	return (c == '"' || c == '\'' || c == ' ');
}

char	*set_word(char *str, t_var *data, t_token **head)
{
	int		x;
	int		y;
	char	*result;

	x = 0;
	y = 0;
	while (str[data->i + x] && !special_characters(str[data->i + x]))
		x++;
	result = malloc (x + 1);
	if (!result)
	{
		printf("messi\n");
		exit(1);
	}
	while (y < x)
	{
		result[y] = str[data->i + y];
		y++;
	}
	result[y] = '\0';
	data->i = data->i + x - 1;
	return (result);
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
			if (str[data.i] == '\0')
				return (head);	
			if (str[data.i] == '"')
				data = double_qoutes(str, data, &head);
			else if (str[data.i] == '\'')
				data = single_qoutes(str, data, &head);
			// else if (!check_special_char(str, data.i))
			// 	data = handle_special_char(str, data, &head);
			else
			{
				printf("ha ana\n");
				token_add_back(&head, new_node(set_word(str, &data, &head), 1, 0, 0));
			}
			if (str[data.i] == '\0')
				return (head);
		}
		data.i++;
	}
	return (head);
}

int main ()
{
	char *str;
	while (1337)
	{
		str = readline("shell sghiwer: ");
		if (!str)
			break;
		add_history(str);
		t_token *head = ft_tokenisation(str);
		while (head)
		{
			printf("================\n");
			printf("type = |%d|\n", head->type);
			printf("in_dq= |%d|\n", head->in_dq);
			printf("in_sq= |%d|\n", head->in_sq);
			printf("word = |%s|\n", head->str);
			printf("================\n");
		// free(head->str);
		head = head->next;
		}
		// printf("Number of words ->%d\n", count_word(str, ' '));
		free(str);
	}
	
	exit (0);
}
