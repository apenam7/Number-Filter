#include <stdio.h>
#include <stdlib.h>
#include "Bit_flag.h"

//void shell_sort(int numbers[], int counter);

int main(int argc, char* argv[])
{
    int i;
    int temp;
    BIT_FLAGS hBit_flags = NULL;
    hBit_flags = bit_flags_init_number_of_bits(2000000000);
	if (hBit_flags == NULL)
	{
		printf("Failed to allocate the memory for the bit_flag object.\n");
		exit(1);
	}
    printf("Create your non-negative integers list and enter -1 anytime to stop: \n");

        scanf("%d", &temp);
        while(temp != -1)
        {
            bit_flags_set_flag(hBit_flags, temp);
            scanf("%d", &temp);
        }

    for (i = 0; i < bit_flags_get_size(hBit_flags); i++)
    {
        if (bit_flags_check_flag(hBit_flags, i))
        {
            printf("%d\n",i);
        }
    }


    /*int* pNumbers;
    int i, j, z;
    int counter = 0;
    int temp;
    pNumbers = (int*)malloc(sizeof(int));
    if (pNumbers == NULL)
	{
		printf("Failed to allocate space for array\n");
		exit(1);
	}
    printf("Create your non-negative integers list and enter -1 anytime to stop: \n");
    while(1)
    {
        scanf("%d", &temp);
        if(temp != -1)
        {
            pNumbers[counter] = temp;
            counter++;
        }
        else
        {
            break;
        }
    }
    //Removing duplicates
    for (i = 0; i < counter; i++)
    {
        for (j = i + 1; j < counter;)
        {
            if (pNumbers[j] == pNumbers[i])
            {
                for (z = j; z < counter; z++)
                {
                    pNumbers[z] = pNumbers[z + 1];
                }
                counter--;
            }
            else
                j++;
        }
    }

    shell_sort( pNumbers, counter); // sorting
    for (i = 0; i < counter; i++) // printing sorted list
    {
        printf("%d\n", pNumbers[i]);
    }*/

    return 0;
}

// shell sort
/*void shell_sort(int numbers[], int counter)
{
	int i;
	int j;
	int temp;
	int h = 1;

	while (h * 3 < counter)
	{
		h <<= 1;
	}
	h--;


	while (h > 0)
	{
		for (i = h; i < counter; i++)
		{
			j = i;
			temp = numbers[j];
			while (j-h + 1 > 0 && temp < numbers[j - h])
			{
				numbers[j] = numbers[j - h];  //shifting
				j-=h;
			}
			numbers[j] = temp;
		}
		h /= 2;
	}
}*/
