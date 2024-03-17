/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:27:44 by qxiang            #+#    #+#             */
/*   Updated: 2024/03/17 11:47:20 by qxiang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dict.h"
#include "ft.h"
#include <stdio.h>

static int	skip_non_numeric(char *str)
{
    int i = 0;
    while (str[i] && !(str[i] >= '0' && str[i] <= '9'))
        i++;
    return i;
}

static int	skip_to_word(char *str)
{
    int i = 0;
    while (str[i] && str[i] != ':' && str[i] != '\n')
        i++;
    if (str[i] == ':')
        i++;
    while (str[i] == ' ')
        i++;
    return i;
}

static int	skip_to_next_entry(char *str)
{
    int i = 0;
    if (str[i] == '\n')
        i++;
    return i;
}

static int	getnbr(char *dest, char *str)
{
	int		i;
	char	c[64];

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		c[i] = str[i];
		i++;
	}
	c[i] = '\0';
	ft_strcpy(dest, c);
	return (i);
}

static int	getword(char *dest, char *str)
{
	int		i;
	char	c[64];

	i = 0;
	while ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
	{
		c[i] = str[i];
		i++;
	}
	c[i] = '\0';
	ft_strcpy(dest, c);
	return (i);
}

t_dict	dict_parse(char *str)
{
	int			i;
	char		*number;
	char		*word;
	t_dict		temp;

	i = 0;
	temp = dict_new();
	while (str[i])
	{
		number = malloc(sizeof(char) * 64);
		word = malloc(sizeof(char) * 64);
		if (!number || !word)
		{
			free(number);
			free(word);
			return (temp);
		}
		i += skip_non_numeric(str + i);
		i += getnbr(number, str + i);
		i += skip_to_word(str + i);
		i += getword(word, str + i);
		i += skip_to_next_entry(str + i);
		//printf("****below is dict_parse\n");
		//printf("number: %s\n", number);
		//printf("word: %s\n", word);
		dict_set(&temp, number, word);
		free(number);
		free(word);
	}
	return (temp);
}
