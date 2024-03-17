/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:27:44 by qxiang            #+#    #+#             */
/*   Updated: 2024/03/17 17:03:04 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dict.h"
#include "ft.h"

static int	skip_non_numeric(char *str);
static int	skip_to_word(char *str);
static int	skip_to_next_entry(char *str);
static int	getnbr(char *dest, char *str);
static int	getword(char *dest, char *str);

int	dict_parse(t_dict *origin, char *str)
{
	int			i;
	char		*number;
	char		*word;

	i = 0;
	while (str[i])
	{
		number = malloc(sizeof(char) * 64);
		word = malloc(sizeof(char) * 64);
		if (!number || !word)
		{
			free(number);
			free(word);
			return (-1);
		}
		i += skip_non_numeric(str + i);
		i += getnbr(number, str + i);
		i += skip_to_word(str + i);
		i += getword(word, str + i);
		i += skip_to_next_entry(str + i);
		dict_set(origin, number, word);
		free(number);
		free(word);
	}
	return (0);
}
