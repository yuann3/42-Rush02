#include <string.h>
const char* words_arr[] = {
	"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

const char* tens_arr[] = {
	"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

char *hundreds_printer(int number)
{
	char result[] = "";
	if (number < 20)
	{
		strcat(result, words_arr[number]);
		return result;
	}
	else if (number < 100)
	{
		int tens = number / 10;
		int ones = number % 10;

		strcat(result, tens_arr[tens]);
		if (ones > 0)
		{
			strcat(result, " ");
			strcat(result, words_arr[ones]);
		}
		return result;
	}
	else
	{
		int hundreds = number / 100;
		int remainder = number % 100;
		
		strcat(result, words_arr[hundreds]);
		strcat(result, " hundred");
		if (remainder > 0)
		{
			strcat(result, " and ");
		}
		strcat(result, hundreds_printer(remainder));
		return result;
	}
}


//test main function
#include <stdio.h>
int main() {
    printf("%s\n", hundreds_printer(5));
    printf("%s\n", hundreds_printer(25));
    printf("%s\n", hundreds_printer(123));
    printf("%s\n", hundreds_printer(999));
    return 0;
}
