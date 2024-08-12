/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pro_max_plus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:09:59 by oumondad          #+#    #+#             */
/*   Updated: 2024/08/10 16:37:20 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include<readline/history.h>

// ls -la > ls | "pwd > out" | diff out ls | echo $? | echo $PATH

typedef struct s_var
{
	int	i;
	int	x;
	int sqflag;
	int	dqflag;
	int words;
}	t_var;

#define S_Q_ON 1
#define S_Q_OFF 0
#define D_Q_ON 1
#define D_Q_OFF 0

t_var	handle_quotes(t_var data, char c)
{
	if (c == '"' && data.sqflag == S_Q_OFF && data.dqflag == D_Q_OFF)
		data.dqflag = D_Q_ON;
	else if (c == '"' && data.dqflag == D_Q_ON)
		data.dqflag = D_Q_OFF;
	if (c == '\'' && data.sqflag == S_Q_OFF && data.dqflag == D_Q_OFF)
		data.sqflag = S_Q_ON;
	else if (c == '\'' && data.dqflag == D_Q_ON)
		data.sqflag = S_Q_OFF;
	return (data);
}

int count_word(char *str, char sep)
{
	t_var data;

	data.i = 0;
	data.x = 0;
	data.sqflag = S_Q_OFF;
	data.dqflag = D_Q_OFF;
	data.words = 0;

	while (str[data.i])
	{
		if (str[data.i] != sep)
		{
			if (data.sqflag == S_Q_OFF && data.dqflag == D_Q_OFF)
				data.words++;
			while (str[data.i] && str[data.i] != sep)
			{
				data = handle_quotes(data, str[data.i]);
				data.i++;
			}
		}
		else
			data.i++;
	}
	return (data.words);
}

int	word_len(char *str, char sep)
{
	int i = 0;
	while (str[i] && str[i] != sep)
		i++;
	return (i);
}

char *get_word(char *str, char sep)
{
	int i = 0;
	char *word;

	word = malloc (word_len(str, sep) + 1);
	while (str[i] && str[i] != sep)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char    **ft_split(char *str, char sep)
{
	int i = 0;
	int y = 0;
    char **result;

    result = malloc ((count_word(str, sep) + 1) * sizeof(char *));
	while (str[i])
	{
		while(str[i] == sep)
			i++;
		if (str[i] && str[i] != sep)
		{
			result[y] = get_word(&str[i], sep);
			y++;
		}
		while (str[i] && str[i] != sep)
			i++;
	}
	result[y] = NULL;
	return (result);
}


int main (int ac, char **av)
{
	// char **result;
	// int i = 0;
	char *str;
	// result = ft_split(av[1], ' ');
	// while (result[i])
	// {
	// 	printf("%s\n", result[i]);
	// 	i++;
	// }
	//printf("Number of words ->%d\n", count_word(av[1], ' '));
	while (1337)
	{
		str = readline("cont word: ");
		if (!str)
			break;
		add_history(str);
		printf("Number of words ->%d\n", count_word(str, ' '));
		free(str);
	}
	return (0);
}
