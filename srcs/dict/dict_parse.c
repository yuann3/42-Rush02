void	dict_parse(char *str)
{
	int	i;
	char	*number;
	char	*word;
	t_dict	dict_entry;

	i = 0;
	dict_entry = dict_new();
	number = malloc(sizeof(char) * 128);
	word = malloc(sizeof(char) * 128);
	number = 0;
	word = 0;
	while (!(str[i] >= '0' && str[i] <= '9'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ft_strcat(number, str[i]);
		i++;
	}
	// number saved into array
	while (str[i] == ' ')
		i++;
	while (str[i] != '\n')
	{
		ft_strcat(word, str[i]);
		i++;
	}
	// word saved into array
	dict_set(dict_entry, number, word);
}
