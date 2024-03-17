/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_break.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 02:38:42 by mamu              #+#    #+#             */
/*   Updated: 2024/03/17 22:44:34 by mamu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dict.h"
#include "ft.h"
#include "nbr.h"

int	nbr_store(t_nbr_buffer *buffer, t_dict *dict, char *str)
{
	char	*word;

	word = dict_get(dict, str);
	if (!word)
		return (-1);
	nbr_buffer_add(buffer, word);
	return (0);
}

int	nbr_print_ones(t_nbr_buffer *buffer, t_dict *dict, char *str)
{
	return (nbr_store(buffer, dict, str));
}

int	nbr_print_tens(t_nbr_buffer *buffer, t_dict *dict, char *str)
{
	int	len;

	len = 2;
	while (*str == '0')
	{
		str++;
		len--;
	}
	if (len == 0)
		return (0);
	if (len == 1)
		return (nbr_print_ones(buffer, dict, nbr_substr(str, 0, 0)));
	if (str[0] == '1')
		return (nbr_store(buffer, dict, str));
	if (nbr_store(buffer, dict, nbr_pad_zero(str[0], 1)) == -1)
		return (-1);
	if (str[1] != '0')
		return (nbr_print_ones(buffer, dict, nbr_substr(str, 1, 1)));
	return (0);
}

int	nbr_print_hundreds(t_nbr_buffer *buffer, t_dict *dict, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len == 1 && str[0] == '0')
		return (nbr_store(buffer, dict, "0"));
	while (*str == '0')
	{
		str++;
		len--;
	}
	if (len == 0)
		return (0);
	if (len == 1)
		return (nbr_store(buffer, dict, str));
	if (len == 2)
		return (nbr_print_tens(buffer, dict, nbr_substr(str, 0, 1)));
	if (nbr_print_ones(buffer, dict, nbr_substr(str, 0, 0)) == -1)
		return (-1);
	if (nbr_store(buffer, dict, "100") == -1)
		return (-1);
	if (nbr_print_tens(buffer, dict, nbr_substr(str, 1, 2)) == -1)
		return (-1);
	return (0);
}

int	nbr_break(t_dict *dict, char *str)
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
		if (nbr_print_hundreds(buffer, dict, digits) == -1)
			return (-1);
		if (remain - n >= 3
			&& !(digits[0] == '0' && digits[1] == '0' && digits[2] == '0'))
			if (nbr_store(buffer, dict, nbr_pad_zero('1', remain - n)) == -1)
				return (-1);
		i += n;
		remain -= n;
	}
	return (nbr_buffer_print(buffer));
}
