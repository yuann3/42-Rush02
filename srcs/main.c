/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:35:27 by welee             #+#    #+#             */
/*   Updated: 2024/03/17 19:00:07 by mamu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	init(char *dict_path, char *input)
{
	t_dict	dict;
	char	*str;

	str = file_read(dict_path);
	dict = dict_new();
	dict_parse(&dict, str);
	nbr_break(&dict, input);
	ft_putchar('\n');
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = check_arg(argc, argv, DEFAULT_DICT);
	if (i == 0)
	{
		ft_error("Error\n");
		return (1);
	}
	else if (i == -1)
	{
		ft_error("Dict Error\n");
		return (1);
	}
	if (argc == 2)
	{
		init(DEFAULT_DICT, argv[1]);
	}
	else if (argc == 3)
	{
		init(argv[1], argv[2]);
	}
	return (0);
}
