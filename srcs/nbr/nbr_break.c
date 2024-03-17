/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_break.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 02:38:42 by mamu              #+#    #+#             */
/*   Updated: 2024/03/17 22:31:02 by mamu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dict.h"
#include "ft.h"
#include "nbr.h"

#include <stdio.h>

static void	nbr_store_word(t_nbr_buffer *buffer, t_dict *dict, char *str)
{
	char	*word;

	word = dict_get(dict, str);
	if (!word)
	{
		ft_putstr("Dict Error\n");
		exit(1);
	}
	nbr_buffer_add(buffer, word);
}

static void	nbr_print_ones(t_nbr_buffer *buffer, t_dict *dict, char *str)
{
	nbr_store_word(buffer, dict, str);
}

static void	nbr_print_tens(t_nbr_buffer *buffer, t_dict *dict, char *str)
{
	int	len;

	len = 2;
	while (*str == '0')
	{
		str++;
		len--;
	}
	if (len == 0)
		return ;
	if (len == 1)
		nbr_print_ones(buffer, dict, nbr_substr(str, 0, 0));
	else if (str[0] == '1')
		nbr_store_word(buffer, dict, str);
	else
	{
		nbr_store_word(buffer, dict, nbr_pad_zero(str[0], 1));
		if (str[1] != '0')
			nbr_print_ones(buffer, dict, nbr_substr(str, 1, 1));
	}
}

static void	nbr_print_hundreds(t_nbr_buffer *buffer, t_dict *dict, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len == 1 && str[0] == '0')
	{
		nbr_store_word(buffer, dict, "0");
		return ;
	}
	while (*str == '0')
	{
		str++;
		len--;
	}
	if (len == 0)
		return ;
	if (len == 1)
		nbr_store_word(buffer, dict, str);
	else if (len == 2)
		nbr_print_tens(buffer, dict, nbr_substr(str, 0, 1));
	else
	{
		nbr_print_ones(buffer, dict, nbr_substr(str, 0, 0));
		nbr_store_word(buffer, dict, "100");
		nbr_print_tens(buffer, dict, nbr_substr(str, 1, 2));
	}
}

void	nbr_break(t_dict *dict, char *str)
{
	int				i;
	int				n;
	int				remain;
	t_nbr_buffer	*buffer;
	char			*digits;

	buffer = nbr_buffer_new();
	i = 0;
	remain = ft_strlen(str);
	while (i < ft_strlen(str))
	{
		n = remain % 3;
		if (n == 0)
			n = 3;
		digits = nbr_substr(str, i, i + n - 1);
		nbr_print_hundreds(buffer, dict, digits);
		if (remain - n >= 3
			&& !(digits[0] == '0' && digits[1] == '0' && digits[2] == '0'))
			nbr_store_word(buffer, dict, nbr_pad_zero('1', remain - n));
		i += n;
		remain -= n;
	}
	nbr_buffer_print(buffer);
}
