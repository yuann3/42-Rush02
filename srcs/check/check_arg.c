/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:05:09 by welee             #+#    #+#             */
/*   Updated: 2024/03/16 19:25:35 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./check/check_digits.h"
#include "./check/check_dict_file.h"

/// @brief check if the arguments are valid
/// @param argc argument count
/// @param argv argument vector
/// @return 1 if the arguments are valid, -1 for  0 otherwise
int	check_arg(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		return (0);
	if (argc == 2)
	{
		if (!check_dict_file(DEFAULT_DICT))
		{
			return (-1);
		}
		if (!check_digits(argv[1]))
			return (0);
	}
	if (argc == 3)
	{
		if (!check_dict_file(argv[1]))
		{
			return (-1);
		}
		if (!check_digits(argv[2]))
			return (0);
	}
	return (1);
}
