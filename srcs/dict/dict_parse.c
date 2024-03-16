
void	dict_parse(char *str)
{
	int	i;
	char	*number;
	char	*word;

	i = 0;
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
}
