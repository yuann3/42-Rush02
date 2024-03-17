/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_type.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamu <mamu@c2r6s9.42singapore.sg>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:19:57 by mamu              #+#    #+#             */
/*   Updated: 2024/03/16 15:48:45 by mamu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_TYPE_H
# define DICT_TYPE_H

typedef struct s_dict
{
	char	**keys;
	char	**values;
	int		size;
}	t_dict;

typedef struct print_number
{
	char	**print;
	int		size;
}	printout;

#endif
