/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamu <mamu@c2r6s9.42singapore.sg>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:21:23 by mamu              #+#    #+#             */
/*   Updated: 2024/03/16 16:04:18 by mamu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict_set.h"

#include <stdlib.h>

static void	str_arr_add(char ***strs, int size, char *str)
{
	char	**strs_new;
	int		i;

	strs_new = malloc(sizeof(**strs) * (size + 1));
	i = 0;
	while (i < size)
	{
		strs_new[i] = *strs[i];
		i++;
	}
	strs_new[i] = str;
	free(*strs);
	*strs = strs_new;
}

void	dict_set(t_dict *dict, char *key, char *value)
{
	str_arr_add(&dict->keys, dict->size, key);
	str_arr_add(&dict->values, dict->size, value);
	dict->size += 1;
}
