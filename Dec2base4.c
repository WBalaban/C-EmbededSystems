#include <stdio.h>
#include <math.h>

void dec_to_base(int num);
void base_to_dec(int num);

int main()
{
	dec_to_base(888);
	base_to_dec(31320);
        
    return 0;
}

void dec_to_base(int num)
{
	char result[32];
	int remainder;
	int i, j = 0;
	printf("Decimal %d converted to base four equals", num);
	while (num != 0)
	{
        remainder = num % 4;
        if (remainder < 10)
            result[j] = 48 + remainder;
        else
            result[j] = 55 + remainder;
        j++;
        num = num / 4;
    }
 
    for (i = j; i >= 0; i--)
        printf("%c", result[i]);
	
}

void base_to_dec(int num)
{
    int dec = 0, i = 0, remainder, tnum = num;
    
    while (tnum!=0)
    {
        remainder = tnum%10;
        tnum /= 10;
        dec += remainder*pow(4,i);
        ++i;
    }
    printf("\nBase four %d converted to decimal equals %d", num, dec);
}


        
