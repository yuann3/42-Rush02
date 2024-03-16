typedef struct dict {
	char *nbr;
	char *word;
}	s_dict;

int	getnb(int digits, char *str)
{
	int	i;
	int	j;
	int	result;
	
	i = 0;
	j = 0;
	result = 0;
	while (i < digits)
	{
		while (str[j] && str[j] >= 48 && str[j] <= 57)
		{
			result *= 10;
			result += str[j] - 48;
			j++;
		}
		i++;
	}
	return (result);
}





int	getword();

s_dict	dict_parse(char *str)
{
	int	i;
	int	j;
	int	k;
	int	digits;
	int	letters;
	s_dict	*rolodex;
	
	i = 0;
	k = 0;
	digits = 0;

	while (*str)
	{
		while (!(str[i] >= '0' && str[i] <= '9'))
			i++;
		j = i;
		while (str[j] >= '0' && str[j] <= '9')
		{
			digits++;
			j++;
		}
		if (digits)
			rolodex[k].nbr = getnb(digits, str + i);
		// number saved into first index
		while (str[i] == ' ')
			i++;
		j = i;
		while (str[j] != '\n')
		{
			letters++;
			j++;
		}
		if (letters)
		{
			rolodex[k].word = getword(letters, str + i);
			k++;
		}
		str
	}
