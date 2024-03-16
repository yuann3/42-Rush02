void hundreds_printer(char *str)
{
	int x = ft_strlen(str);
	char num_str[3];
	if (str == 3)
	{
		single_printer(str[0]);
		write(1, "hundred", 7);
		if (str[1] != '0' && str[2] != '0')
			write(1, " and ", 5);
		tens_printer(str + 1);
		return (atoi(str[0]);
	}
	else if (str == 2)
	{
		tens_printer(str);
		return (0);
	}
	else if (str == 1)
	{
			
	}
}

char *tens_printer(char *nbr)
{
	int nb = atoi(nbr);
	char *print;
	if (nb >= 90)
		print = strdup("ninety");
	else if (nb >= 80)
		print = strdup("eighty");
	else if (nb >= 70)
		print = strdup("seventy");
	else if (nb >= 60)
		print = strdup("sixty");
	else if (nb >= 50)
		print = strdup("fifty");
	else if (nb >= 40)
		print = strdup("fourty");
	else if (nb >= 30)
		print = strdup("thirty");
	else if (nb >= 20)
		print = strdup("twenty");
	else if (nb <= 20)
		print = word_finder(nb);

void single_printer(char c)
{
	write(1, &c, 1);
}


#include <stdio.h>
int main()
{
	//test main function
	char a[4] = "321";
	char *print = hundreds_printer(a);
	printf("%s\n", print);
