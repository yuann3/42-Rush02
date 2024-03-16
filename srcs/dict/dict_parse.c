/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxiang <qxiang@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:27:44 by qxiang            #+#    #+#             */
/*   Updated: 2024/03/16 17:06:06 by qxiang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict_parse.h"
#include "dict_new.h"
#include "dict_set.h"
#include "ft_strcat.h"
#include <stdlib.h>

void	dict_parse(char *str)
{
	int	i;
	char	*number;
	char	*word;
	t_dict	dict_entry;

	i = 0;
	dict_entry = dict_new();
	number = malloc(sizeof(char) * 128);
	word = malloc(sizeof(char) * 128);
	number = 0;
	word = 0;
	while (!(str[i] >= '0' && str[i] <= '9'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ft_strcat(number, str[i]);
		i++;
	}
	// number saved into array
	while (str[i] == ' ')
		i++;
	while (str[i] != '\n')
	{
		ft_strcat(word, str[i]);
		i++;
	}
	// word saved into array
	dict_set(dict_entry, number, word);
}
