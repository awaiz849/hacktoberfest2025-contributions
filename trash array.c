#include<stdio.h>
#include<conio.h>

// In this function we will accept and fill array elemnets
void fill_array(int b[], int sz)
{
	int i;
	printf("Enter %d elements\n", sz);
	for(i=0; i<sz; i++)
	{
		scanf("%d", &b[i]);
	}
}

void shift_in_trash(int b[], int sz, int ind_to_remove, int trash[], int trash_index)
{
	int i;
	// step A: selected element is moved to trash at trash_index
	trash[trash_index] = b[ind_to_remove];

	//step B: now shifting elements one step backward
	for(i=ind_to_remove; i<sz-1; i++)
	{
		b[i] = b[i+1];
	}
	b[sz-1] = 0;
}

int remove_specific_elements(int b[], int sz, int trash[])
{
	int i, trash_index = 0;
	for(i=0; i<sz; i++)
	{
		if(b[i] % 10 == 3)
		{
			shift_in_trash(b, sz, i, trash, trash_index);
			i--;
			trash_index++;
		}
	}

	return trash_index;
}

void display_elements(int b[], int sz)
{
	int i;
	if(sz==-1)
	{
		printf("Trash is Empty.\n");
	}
	else
	{
	   for(i=0; i<sz; i++)
	   {
		printf("%d  ", b[i]);
	   }
	}
}

void main()
{
	int array[10], trash[10];
	int i, trash_size;

	clrscr();
	// step 1 - accepting array elements
	fill_array(array, 10);

	// step 2 - removing elements that ends with 3
	trash_size = remove_specific_elements(array, 10, trash);

	// step 3 - displaying original array and trash array
	printf("\nElements of actual array\n");
	display_elements(array, 10);
	printf("\nElements of Trash array\n");
	display_elements(trash, trash_size);

	getch();

}

