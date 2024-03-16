/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_mock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:21:30 by mamu              #+#    #+#             */
/*   Updated: 2024/03/16 17:48:13 by welee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

t_dict	dict_mock(void)
{
	t_dict	dict;

	dict = dict_new();
	dict_set(&dict, "0", "zero");
	dict_set(&dict, "1", "one");
	dict_set(&dict, "2", "two");
	dict_set(&dict, "3", "three");
	dict_set(&dict, "4", "four");
	dict_set(&dict, "5", "five");
	dict_set(&dict, "6", "six");
	dict_set(&dict, "7", "seven");
	dict_set(&dict, "8", "eight");
	dict_set(&dict, "9", "nine");
	dict_set(&dict, "10", "ten");
	dict_set(&dict, "11", "eleven");
	dict_set(&dict, "12", "twelve");
	dict_set(&dict, "13", "thirteen");
	dict_set(&dict, "14", "forteen");
	dict_set(&dict, "15", "fifteen");
	dict_set(&dict, "16", "sixteen");
	dict_set(&dict, "17", "seventeen");
	dict_set(&dict, "18", "eighteen");
	dict_set(&dict, "19", "nineteen");
	dict_set(&dict, "20", "twenty");
	dict_set(&dict, "30", "thirty");
	dict_set(&dict, "40", "forty");
	dict_set(&dict, "50", "fifty");
	dict_set(&dict, "60", "sixty");
	dict_set(&dict, "70", "seventy");
	dict_set(&dict, "80", "eighty");
	dict_set(&dict, "90", "ninety");
	dict_set(&dict, "100", "hundred");
	dict_set(&dict, "1000", "thousand");
	dict_set(&dict, "1000000", "million");
	dict_set(&dict, "1000000000", "billion");
	dict_set(&dict, "1000000000000", "trillion");
	dict_set(&dict, "1000000000000000", "quadrillion");
	dict_set(&dict, "1000000000000000000", "quintillion");
	dict_set(&dict, "1000000000000000000000", "sextillion");
	dict_set(&dict, "1000000000000000000000000", "septillion");
	dict_set(&dict, "1000000000000000000000000000", "octillion");
	dict_set(&dict, "1000000000000000000000000000000", "nonillion");
	dict_set(&dict, "1000000000000000000000000000000000", "decillion");
	dict_set(&dict, "1000000000000000000000000000000000000", "undecillion");
	return (dict);
}
