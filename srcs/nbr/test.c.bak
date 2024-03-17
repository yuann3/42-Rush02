#include "ft.h"
#include <stdio.h>
#include "dict.h"
#include <stdlib.h>

char	*ft_digit_with_zeros(char c, int zeros)
{
	char *p;
	int	i;
	int	len;

	len = 1 + zeros;
	p = malloc(len + 1);

	p[0] = c;
	i = 1;
	while (i < len)
	{
		p[i] = '0';
		i++;
	}
	p[i] = '\0';
	return (p);
}

void nbr_break(t_dict *dict, char *test, char *placeholder)
{
	int len;
	char *comp;
	char empty[20] = "";

	len = ft_strlen(test);
	if (len == 0)
		return ;
	if (len == 1 || (len == 2 && test[0] == '1'))
	{
		ft_putstr(dict_get(dict, test));
		printf("\n");
		return ;
	}
	if (len == 2)
	{
		ft_putstr(dict_get(dict, ft_digit_with_zeros(test[0], 1)));
		printf("\n");
		nbr_break(dict, test + 1, placeholder);
		return ;
	}
	comp = ft_digit_with_zeros('1', len - 1);
	ft_strncat(placeholder, test, 1);
	if (!dict_get(dict, comp))
	{
		nbr_break(dict, ++test, placeholder);
		return ;
	}
	nbr_break(dict, placeholder, empty);
	ft_putstr(dict_get(dict,comp));
	printf("\n");
	nbr_break(dict, ++test, empty);
}
