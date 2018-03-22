#include <stdio.h>

int add_base(int x, int y);
int sub_base(int x, int y);

int main()
{
	int num1, num2;
	char op;
	
	printf("Submit first base 4 number: ");
	scanf("%d", &num1);
	
	printf("Submit second base 4 number: ");
	scanf("%d", &num2);
	
	printf("Type '+' or '-' for desired operation: ");
	scanf(" %c", &op);
	getchar();
	
	while((op!='+') && (op!='-'))
	{
		printf("You can only use '+' or '-', try again: ");
		scanf(" %c", &op);
		getchar();
	}
	
	if(op == '+')
		printf("%d + %d = %d",num1, num2, add_base(num1, num2));
	else
		printf("%d - %d = %d",num1, num2, sub_base(num1, num2));
		
	printf("\nGoodbye!\n");
	

	
	return 0;
}


int add_base(int a, int b)
{
    int sum = 0, move = 0, position = 0, position_mult = 1;

    while (a > 0 || b > 0 || move)
    {
        position = a % 10 + b % 10 + move;

        if (position > 3)
        {
            move = 1;
            position %= 4;
        }
        else
            move = 0;

        sum += position * position_mult;
        position_mult *= 10;
        a /= 10;
        b /= 10;
    }
    return sum;
}

int sub_base(int a, int b)
{
	int sum = 0;
	
	if(a>b)  // Odejmowanie przez dodawanie przy u¿yciu funkcji dodawania
	{
		int i = 34 - b;
		sum = add_base(a, i) - 100;
	}
	else
	{
		int i = 34 - a;
		sum = add_base(b, i) - 100;
		sum *= -1;
	}
	
	return sum;
}



