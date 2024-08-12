/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:18:38 by oumondad          #+#    #+#             */
/*   Updated: 2024/08/12 19:42:27 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headr_mo2a9at.h"

int	on_off(int x)
{
	if (x == 0)
		return (1);
	if (x == 1)
		return (0);
}

int	is_ws(char c)
{
	if (c >= 9 && c <= 13 || c == ' ')
		return (1);
	return (0);
}

int	is_sc(char c)
{
	if (c == '|' || c == '>' || c == '<' || c == ' ')
		return (1);
	return (0);
}

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

int	ft_len_word(char *str, t_var *data)
{
	int	i;
	int	fl_sq;
	int	fl_dq;

	i = 0;
	fl_sq = 0;
	fl_dq = 0;
	while (1)
	{
		while (str[i] && str[i] != '"' && str[i] != '\'' && is_ws(str[i]))
			i++;
		if (str[i] == '"' || str[i] == '\'')
		{
			if (str[i] == '"' && fl_sq == 0)
				fl_dq = on_off(fl_dq);
			if (str[i] == '\'' && fl_dq == 0)
				fl_sq = on_off(fl_sq);
		}
		if (!str[i] && (fl_sq || fl_dq))
		{
			data->i += i;
			return (-1);
		}
		if (fl_sq == 0 && fl_dq == 0 && (str[i] == '\0' || str[i + 1] == '\0'
			|| is_ws(str[i + 1]) || is_sc(str[i + 1])))
			return (i + 1);
		i++;
	}
	return (-1);
}

char *get_word(char *str, t_var *data, char c)
{
	char	*result;
	int		j;
	int		len;

	j = 0;
	len = ft_len_word(&str[data->i], data);
	if (len == -1)
	{
		result = "Error";
		return (result);
	}
	result = malloc (len + 1);
	while (j < len)
	{
		result[j] = str[data->i + j];
		j++;
	}
	result[j] = '\0';
	data->i = data->i + j - 1;
	return (result);
}

t_var	double_quotes(char *str, t_var data, t_token **head)
{
	if (!check_q_in_str(&str[data.i], '"'))
		token_add_back(head, new_node("\"", ERROR, 0, 0));
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

t_var	single_quotes(char *str, t_var data, t_token **head)
{
	if (!check_q_in_str(&str[data.i], '\''))
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

char	*set_word(char *str, t_var *data, t_token **head)
{
	int		j;
	int		len;
	char	*result;

	j = 0;
	len = ft_len_word(&str[data->i], data);
	if (len == -1)
	{
		result = "Error";
		return (result);
	}
	result = malloc (len + 1);
	if (!result)
		exit(1);
	while (j < len)
	{
		result[j] = str[data->i + j];
		j++;
	}
	result[j] = '\0';
	data->i = data->i + len - 1;
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
		if (!is_ws(str[data.i]))
		{
			if (str[data.i] == '"')
				data = double_quotes(str, data, &head);
			else if (str[data.i] == '\'')
				data = single_quotes(str, data, &head);
			// else if (str[data.i] == '|' || str[data.i] == '>' || str[data.i] == '<')
			// 	data = handle_special_char(str, data, &head);
			else
				token_add_back(&head, new_node(set_word(str, &data, &head), 1, 0, 0));
			if (str[data.i] == '\0')
				return (head);
		}
		data.i++;
	}
	return (head);
}

int main(void)
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
		head = head->next;
		}
		// printf("Number of words ->%d\n", count_word(str, ' '));
		free(str);
	}
}

//== Test Examples==//

// "echo"this"is         """"   ""one""word"
// < infile | echo "Hello '$USER'" > out
// ls -la|echo "Hello"sdfsdf> out