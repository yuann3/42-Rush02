/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:35:27 by welee             #+#    #+#             */
/*   Updated: 2024/03/17 10:38:33 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
void nbr_break(t_dict *dict, char *str);
#include <stdio.h>

int	init(char *dict_path, char *input)
{
	t_dict	dict;
	char	*str;

	(void)input;
	str = file_read(dict_path);
	//printf("%s", str);
	dict = dict_parse(str);
	//printf("dict get for 1: %s\n", dict_get(&dict, "1"));
	nbr_break(&dict, input);
	printf("\n");
	//printf("%s\n",dict.keys[0]);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = check_arg(argc, argv);
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
