#include <stdio.h>
#include <stdlib.h>

#define BUFFER_LEN 100
#define LOG_LOW(user_input) log_add(__DATE__, __TIME__,  __FILE__, __LINE__, "LOW", user_input)
#define LOG_MEDIUM(user_input) log_add(__DATE__, __TIME__,  __FILE__, __LINE__, "MEDIUM", user_input)
#define LOG_HIGH(user_input) log_add(__DATE__, __TIME__,  __FILE__, __LINE__, "HIGH", user_input)
#define LOG_ERROR(user_input) log_add(__DATE__, __TIME__,  __FILE__, __LINE__, "ERROR", user_input)


void log_add(char* date, char* time, char* file, int line, char* log_name, char* input);

int main()
{		
  	LOG_LOW("Within buffer limits");
  	
  	LOG_MEDIUM("Getting close to buffer overflow");
  	
  	LOG_HIGH("LOOK OUT! GETTING VERY CLOSE TO BUFFER LIMIT!");
  	
  	LOG_ERROR("ERROR! BUFFER OVERFLOWN! Plese check logger.txt for your current log!");
  
    return 0; 
}

void log_add(char* date, char* time, char* file, int line, char* log_name, char* input)
{
	char buffer[BUFFER_LEN];
	int len = snprintf(NULL, 0, "%s | %s | %s:%d | %s | %s \n", 
						date, time, file, line, log_name, input);     // sprawdzamy d³ugoœæ logu

	if (len > BUFFER_LEN) // Jeœli d³ugoœæ jest wiêksza od wielkoœcu bufera, robimy zapis do pliku
	{
		FILE *f_write;
		f_write = fopen("my_logger.txt","w");
		
		if(f_write == NULL)
   		{
      		printf("Error!");   
      		exit(0);             
   		}
   		fprintf(f_write, "%s | %s | %s:%d | %s | %s \n", date, time, file, line, log_name, input);
   		fclose(f_write);
   		
		FILE *f_read;
		f_read = fopen("my_logger.txt","r");
		
		if (f_read != NULL)
		{
			int c;

        	while ((c = fgetc(f_read)) != EOF)   
        	{
            	putchar(c);                   
        	}
		}
		fclose(f_read);
    }
	else // jeœli jest wystarczaj¹ca iloœæ miejsca w buferze, wprwoadzamy log do bufera
	{
		sprintf(buffer, "%s | %s | %s:%d | %s | %s \n", date, time, file, line, log_name, input);
		puts(buffer);
	}
	
}
