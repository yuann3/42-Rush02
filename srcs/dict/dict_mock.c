/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_mock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamu <mamu@c2r6s9.42singapore.sg>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:21:30 by mamu              #+#    #+#             */
/*   Updated: 2024/03/16 15:35:07 by mamu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict_mock.h"

#include "dict_new.h"
#include "dict_set.h"

t_dict	dict_mock(void)
{
	t_dict	dict;

	dict = dict_new();
	dict_set(&dict, "0", "zero");
	dict_set(&dict, "1", "one");
	return (dict);
}
