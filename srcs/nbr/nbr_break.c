/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_break.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 02:38:42 by mamu              #+#    #+#             */
/*   Updated: 2024/03/17 18:42:54 by mamu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dict.h"
#include "ft.h"
#include "nbr.h"

/// @brief print a string followed by a newline
/// @param str string
void	ft_putstrsp(t_dict *dict, char *str)
{
	if (dict_get(dict, str) == 0)
		exit(1);
	else
	{
		ft_putstr(dict_get(dict, str));
		ft_putchar(' ');
	}
}

/// @brief print the ones place of a number
/// @param dict dictionary
/// @param str number
void	nbr_print_ones(t_dict *dict, char *str)
{
	ft_putstrsp(dict, str);
}

/// @brief print the tens place of a number
/// @param dict dictionary
/// @param str number
void	nbr_print_tens(t_dict *dict, char *str)
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
		nbr_print_ones(dict, nbr_substr(str, 0, 0));
	else if (str[0] == '1')
		ft_putstrsp(dict, str);
	else
	{
		ft_putstrsp(dict, nbr_pad_zero(str[0], 1));
		if (str[1] != '0')
			nbr_print_ones(dict, nbr_substr(str, 1, 1));
	}
}

void	nbr_print_hundreds(t_dict *dict, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len == 1 && str[0] == '0')
	{
		ft_putstrsp(dict, "0");
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
		ft_putstrsp(dict, str);
	else if (len == 2)
		nbr_print_tens(dict, nbr_substr(str, 0, 1));
	else
	{
		nbr_print_ones(dict, nbr_substr(str, 0, 0));
		ft_putstrsp(dict, "100");
		nbr_print_tens(dict, nbr_substr(str, 1, 2));
	}
}

void	nbr_break(t_dict *dict, char *str)
{
	int		i;
	int		n;
	int		len;
	int		remain;

	i = 0;
	len = ft_strlen(str);
	remain = len;
	while (i < len)
	{
		n = remain % 3;
		if (n == 0)
			n = 3;
		nbr_print_hundreds(dict, nbr_substr(str, i, i + n - 1));
		if (remain - n >= 3)
			ft_putstrsp(dict, nbr_pad_zero('1', remain - n));
		i += n;
		remain -= n;
	}
}
