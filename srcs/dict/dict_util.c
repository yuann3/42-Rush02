/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:30 by welee             #+#    #+#             */
/*   Updated: 2024/03/17 17:06:02 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	skip_non_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		i++;
	return (i);
}

int	skip_to_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ':' && str[i] != '\n')
		i++;
	if (str[i] == ':')
		i++;
	while (str[i] == ' ')
		i++;
	return (i);
}

int	skip_to_next_entry(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\n')
		i++;
	return (i);
}

int	getnbr(char *dest, char *str)
{
	int		i;
	char	c[64];

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		c[i] = str[i];
		i++;
	}
	c[i] = '\0';
	ft_strcpy(dest, c);
	return (i);
}

int	getword(char *dest, char *str)
{
	int		i;
	char	c[64];

	i = 0;
	while ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
	{
		c[i] = str[i];
		i++;
	}
	c[i] = '\0';
	ft_strcpy(dest, c);
	return (i);
}
