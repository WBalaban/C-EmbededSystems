#include <stdio.h>


void swap (int *a, int *b);
void sort(int *a, int *b, int *c);

void main()
{
	int a = 3;
	int b = 2;
	int c = 1;
	
	int * pa = &a;
	int * pb = &b;
	int * pc = &c;
	
	printf("a = %d  b = %d c = %d", a, b, c);
	
	sort (pa, pb, pc);

	
}

// Zamiana dwóch liczb przy u¿yciu wskaŸników
void swap (int * a, int * b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

// Funkcja sortuj¹ca przy u¿yciu funckji swap
void sort(int *a, int *b, int * c)
{
	if (*a > *c)
		swap (a, c);
	if (*a > *b)
		swap(a, b);
	if (*b > *c)
		swap(b, c);
	printf("\n%d, %d, %d.", *a, *b, *c);

}


