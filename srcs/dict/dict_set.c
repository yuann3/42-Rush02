/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamu <mamu@c2r6s9.42singapore.sg>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:21:23 by mamu              #+#    #+#             */
/*   Updated: 2024/03/16 16:44:57 by mamu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict_set.h"

#include <stdlib.h>

static char	**str_arr_add(char **strs, int size, char *str)
{
	char	**arr;
	int		i;

	arr = malloc(sizeof(*strs) * (size + 1));
	i = 0;
	while (i < size)
	{
		arr[i] = strs[i];
		i++;
	}
	arr[i] = str;
	return (arr);
}

void	dict_set(t_dict *dict, char *key, char *value)
{
	char	**keys;
	char	**values;

	keys = str_arr_add(dict->keys, dict->size, key);
	free(dict->keys);
	dict->keys = keys;
	values = str_arr_add(dict->values, dict->size, value);
	free(dict->values);
	dict->values = values;
	dict->size += 1;
}
