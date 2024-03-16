/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:58:23 by welee             #+#    #+#             */
/*   Updated: 2024/03/16 09:36:29 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_putchar.h"

/// @brief print string
/// @param str string to be printed
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}
