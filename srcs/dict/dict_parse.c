/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:27:44 by qxiang            #+#    #+#             */
/*   Updated: 2024/03/17 17:14:07 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dict.h"
#include "ft.h"

int	skip_non_numeric(char *str);
int	skip_to_word(char *str);
int	skip_to_next_entry(char *str);
int	getnbr(char *dest, char *str);
int	getword(char *dest, char *str);

/// @brief parsing the string and store the key-value pair in the dictionary
/// @param origin dictionary
/// @param str the string to be parsed
/// @return 0 if success, -1 if malloc failed
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
