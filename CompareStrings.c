#include <stdio.h>
#include <stdbool.h>

#define MAX 50     // maksymalna d³ugoœæ stringa

bool comapareStrings(char * str1, char * str2);

int main()
{
	char str1[MAX];
	char str2[MAX];
	int test;
	
	printf("Podaj pierwszy string: ");
	fgets(str1, sizeof str1, stdin);

	printf("Podaj drugi string: ");
	fgets(str2, sizeof str2, stdin);
	
		
	printf(comapareStrings(str1,str2) ? "true" : "false");

	
}

// funckja porównuj¹ca stringi
bool comapareStrings(char * str1, char * str2)
{
	int num1 = strlen(str1);
	int num2 = strlen(str2);
	
	int counter = 0;
	while(*str1==*str2)
	{
		if ( *str1 == '\0' || *str2 == '\0' ) // szukamy znaku koñca ³añcucha znakowego
    		break;
    	str1++;
    	str2++;
    	counter++;
	}

	if(num1 == counter && num2 == counter)
    	return true;
	else
		return false;
}



