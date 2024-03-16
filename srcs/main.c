/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:35:27 by welee             #+#    #+#             */
/*   Updated: 2024/03/16 20:30:01 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	int	i;

	i = check_arg(argc, argv);
	if (i == 0)
	{
		ft_error("Error\n");
		return (1);
	}
	if (i == -1)
	{
		ft_error("Dict Error\n");
		return (1);
	}
	if (argc == 2)
	{

	}
	if (argc == 3)
	{

	}
	return (0);
}
