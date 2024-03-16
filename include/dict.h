/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamu <mamu@c2r6s9.42singapore.sg>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:10:57 by mamu              #+#    #+#             */
/*   Updated: 2024/03/16 15:12:30 by mamu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include "dict_get.h"
# include "dict_mock.h"

typedef struct s_dict
{
	char	*keys;
	char	*values;
}	t_dict;

#endif
