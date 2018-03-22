#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char *intToStrSupport(int number, char *bufor);
char *intToStr(int number, char *bufor);

int main()
{
	
	int num, intLen;
	char * str;

  	printf ("Podaj liczbe calkowita, ktora chcesz przekonwertowac: ");
  	scanf ("%d", &num);
  	
	if(num==0)
  		intLen = 1;
  	else
		intLen = floor(log10(abs(num))) + 1;

  	str = (char*) malloc (intLen+1); // dynamiczna alokacja pamiêci
	
	str = intToStr(num, str);
	
	printf("Po przekonwertowaniu: \"%s\"", str);
	
	free(str);  // zwalniamy pamiec
	
}

char *intToStrSupport(int number, char *bufor) // funckja pomocnicza dla intToStr
{
	if (number <= -10) 
    	bufor = intToStrSupport(number/10, bufor);
	*bufor++ = '0' - number%10;
	return bufor;
}

char *intToStr(int number, char *bufor) // funckja conwertujaca int na str i wywolujaca funckje pomocnicza
{
	char *temp = bufor;
	if (number < 0) 
		*temp++ = '-';
	else 
    	number = -number;
  *intToStrSupport(number, temp) = '\0';
  return bufor;
}

