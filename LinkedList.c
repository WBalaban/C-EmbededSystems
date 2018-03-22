#include <stdio.h>

struct ListElem
{
	int num;
	struct ListElem* prev;
	struct ListElem* next;
};

int main()
{
	struct ListElem elem_1;
	struct ListElem elem_2;
	struct ListElem elem_3;
	struct ListElem *list_pointer =&elem_1;

	
	elem_1.num = 1;
	elem_1.prev = NULL;
	elem_1.next = &elem_2;
	
	elem_2.num = 20;
	elem_2.prev = &elem_1;
	elem_2.next = &elem_3;
	
	elem_3.num = 300;
	elem_3.prev = &elem_2;
	elem_3.next = (struct ListElem *) 0;
	
	while (list_pointer != (struct entry *) 0 )
	{
    printf("%i\n", list_pointer->num);
    list_pointer = list_pointer -> next;
	}
}
	


