/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:27:44 by qxiang            #+#    #+#             */
/*   Updated: 2024/03/16 21:10:39 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dict.h"
#include "ft.h"

static int	getnbr(char *dest, char *str)
{
	int		i;
	char	c[2];

	i = 0;
	c[1] = '\0';
	while (str[i] >= '0' && str[i] <= '9')
	{
		c[0] = str[i];
		ft_strcat(dest, c);
		i++;
	}
	return (i);
}

static int	getword(char *dest, char *str)
{
	int		i;
	char	c[2];

	i = 0;
	c[1] = '\0';
	while ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
	{
		c[0] = str[i];
		ft_strcat(dest, c);
		i++;
	}
	return (i);
}

t_dict	dict_parse(char *str)
{
	int			i;
	char		*number;
	char		*word;
	t_dict		dict_entry;

	i = 0;
	dict_entry = dict_new();
	number = malloc(sizeof(char) * 128);
	word = malloc(sizeof(char) * 128);
	number = 0;
	word = 0;
	while (!(str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] >= '0' && str[i] <= '9')
		i += getnbr(number, str + i);
	while (!(str[i] >= 65 && str[i] <= 90) || !(str[i] >= 97 && str[i] <= 122))
		i++;
	if (str[i] != '\n')
		i += getword(word, str + i);
	dict_set(&dict_entry, number, word);
	return (dict_entry);
}
