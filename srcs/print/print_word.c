/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 19:20:44 by cgoh              #+#    #+#             */
/*   Updated: 2024/03/16 21:09:39 by cgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "dict.h"
#include "ft.h"

void	print_thousand(char *num, t_dict *dict)
{
	write(1, dict_get(dict, num), ft_strlen(num));
}

void	print_thousands_sep(char *thousands_sep, char *num, t_dict *dict)
{
	int	i;

	thousands_sep = malloc((ft_strlen(num) + 1) * sizeof(char));
	thousands_sep[0] = '1';
	i = 0;
	while (i < ft_strlen(num) + 1)
	{
		thousands_sep[i] = '0';
		i++;
	}
	thousands_sep[i] = '\0';
	write(1, dict_get(dict, thousands_sep), ft_strlen(thousands_sep));
}

void	print_name(char *num, t_dict *dict)
{
	char	thousand[3];
	char	*thousands_sep;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < ft_strlen(num))
	{
		j = 0;
		while (num[i] && j < 3 && (ft_strlen(num[i]) % 3 != 0))
		{
			thousand[j] = num[i];
			i++;
			j++;
		}
		print_thousand(thousand, dict);
		if (ft_strlen(num[i]) > 0)
			print_thousands_sep(thousands_sep, num[i], dict);
	}
}