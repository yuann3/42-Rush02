/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamu <mamu@c2r6s9.42singapore.sg>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 02:38:42 by mamu              #+#    #+#             */
/*   Updated: 2024/03/17 06:01:03 by mamu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>
#include "dict.h"
#include <stdlib.h>

char	*substr(char *str, int from, int to)
{
	char	*s;
	int		len;
	int		i;

	i = 0;
	len = to - from + 1;
	s = malloc(len + 1);
	while (i < len)
	{
		s[i] = str[from + i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*nbr_pad_zero(char c, int zeros)
{
	char	*p;
	int		i;
	int		len;

	len = 1 + zeros;
	p = malloc(len + 1);
	p[0] = c;
	i = 1;
	while (i < len)
	{
		p[i] = '0';
		i++;
	}
	p[i] = '\0';
	return (p);
}

void	nbr_print_ones(t_dict *dict, char *str)
{
	ft_putstr(dict_get(dict, str));
}

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
		nbr_print_ones(dict, substr(str, 0, 0));
	else if (str[0] == '1')
		ft_putstr(dict_get(dict, str));
	else
	{
		ft_putstr(dict_get(dict, nbr_pad_zero(str[0], 1)));
		if (str[1] != '0')
			nbr_print_ones(dict, substr(str, 1, 1));
	}
}

void	nbr_print_hundreds(t_dict *dict, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len == 1 && str[0] == '0')
	{
		ft_putstr(dict_get(dict, "0"));
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
		ft_putstr(dict_get(dict, str));
	else if (len == 2)
		nbr_print_tens(dict, substr(str, 0, 1));
	else
	{
		nbr_print_ones(dict, substr(str, 0, 0));
		ft_putstr(dict_get(dict, "100"));
		nbr_print_tens(dict, substr(str, 1, 2));
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
		nbr_print_hundreds(dict, substr(str, i, i + n - 1));
		if (remain - n >= 3)
			ft_putstr(dict_get(dict, nbr_pad_zero('1', remain - n)));
		i += n;
		remain -= n;
	}
}
