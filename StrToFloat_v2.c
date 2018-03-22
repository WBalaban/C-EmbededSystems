#include <stdio.h>
#include <stdlib.h>

float strToFloat(char* str);

int main()
{
	char * str;
	
	printf("Podaj string, ktory chcesz zmienic na float: ");
	str = (char*) malloc (256);
	
	if(!str)              // zapewniamy odpowiedni¹ iloœæ pamiêci
  		perror("malloc");
	else
  		scanf("%255s", str);	
	
	printf("Po przeksztalceniu: %f.", strToFloat(str));

}

float strToFloat(char* str)
{
	float count = 0, multiply = 1;
	int coma;
	if (*str == '-')   // sprawdzamy czy liczba jest ujemna
	{
		str++;
		multiply = -1;
	};
	
	for (coma = 0; *str; str++)
	{
		if (*str == '.') // szukamy kropki
		{
    		coma = 1; 
      		continue;
    	};
    	int i = *str - '0';
    	if (i >= 0 && i <= 9)
		{
			if (coma) multiply /= 10.0f;
			count = count * 10.0f + (float)i;
    	};
	};
	return count * multiply; // zwracamy wynik pomno¿ony przez -1 jeœli liczba jest ujemna
};






