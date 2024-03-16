/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:35:27 by welee             #+#    #+#             */
/*   Updated: 2024/03/16 17:15:16 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "check.h"

int	main(int argc, char **argv)
{
	if (!check_arg(argc, argv))
	{
		ft_error("Error\n");
		return (1);
	}
	return (0);
}
