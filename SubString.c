#include <stdio.h>

void substring(char * source, int beginning,  
               int number, char *result);

int main()
{
	char *str = "Wcale nie chce mi sie spac";
	int start = 10;
	int howMany = 16;
	char strPart[howMany+1];
	substring(str, start, howMany, strPart);
	
	printf("Oryginalny tekst: \"%s\", zaczynamy od indeksu numer "
			"%d, ktory stanowi litere %c, przesuwamy sie o\n %d "
			"pozycji i otrzymujemy nastepujacy tekst: \"%s\".",
			str, start, str[start], howMany, strPart);

}

void substring(char* source, int beginning,  
               int number, char* result)
{
	int i = 0;
	int j = beginning + number;
	for(beginning; beginning < j; beginning++)
	{
		result[i] = source[beginning];
		i++;
	}
	result[i] = '\0';
}


