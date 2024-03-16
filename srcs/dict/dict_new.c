/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamu <mamu@c2r6s9.42singapore.sg>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:28:55 by mamu              #+#    #+#             */
/*   Updated: 2024/03/16 15:45:06 by mamu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict_new.h"

#include <stdlib.h>

static char	**str_arr_new(void)
{
	char	**arr;

	arr = malloc(sizeof(*arr));
	arr[0] = 0;
	return (arr);
}

t_dict	dict_new(void)
{
	t_dict	dict;

	dict.keys = str_arr_new();
	dict.values = str_arr_new();
	dict.size = 0;
	return (dict);
}
