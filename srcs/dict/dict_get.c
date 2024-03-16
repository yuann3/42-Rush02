/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamu <mamu@c2r6s9.42singapore.sg>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:21:23 by mamu              #+#    #+#             */
/*   Updated: 2024/03/16 17:43:55 by cgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict_get.h"
#include "ft_strcmp.h"

char	*dict_get(t_dict *dict, char *key)
{
	int	i;

	i = 0;
	while (i < dict->size)
	{
		if (strcmp(key, dict->keys[i]) == 0)
			return (dict->values[i]);
		i++;
	}
	return (0);
}
