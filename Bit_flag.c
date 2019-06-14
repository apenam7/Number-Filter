#include <stdio.h>
#include <stdlib.h>
#include "Bit_flag.h"
#include "status.h"

struct bit_flags{

    int size;
    int capacity;
    int* data;

};

typedef struct bit_flags Bit_flags;
const int size_of_int = sizeof(unsigned int)*8;

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits)
{
    int index = 0;
    int i = 0;
    Bit_flags* pBit_flags;
    if (number_of_bits > 0)// if the given number is positive
        {
            pBit_flags = (Bit_flags*)malloc(sizeof(Bit_flags));//asking for memory
            if (pBit_flags != NULL)
                {
                    if(number_of_bits % size_of_int)
                    {
                        index = (number_of_bits / size_of_int) + 1;
                    }
                    else
                    {
                        index = number_of_bits / size_of_int;
                    }
                    pBit_flags->capacity = index * size_of_int;
                    pBit_flags->size = number_of_bits;
                    pBit_flags->data = (int*)malloc(index * sizeof(int));//asking for memory
                    if (pBit_flags->data == NULL)
                    {
                        printf("Could not allocate memory for bit value\n");
                        free(pBit_flags->data);
                        free(pBit_flags);
                        pBit_flags = NULL;//In case of failure return NULL
                        return NULL;
                    }
                    else
                    {
                        for(i=0; i<index; i++)
                        {
                            pBit_flags->data[i] = 0;
                        }
                    }
                }
                printf("Bit flags object created\n");
        }
    else //if the number is negative or zero
    {
        printf("Number of bits can not a negative or zero");
        pBit_flags = NULL;//In case of failure return NULL
    }

    return (BIT_FLAGS)pBit_flags;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    int* pTemp;
    int i;
    int index = 0;
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags; //cast the void* object to a Bit_flag* object
    if ((flag_position) >= pBit_flags->capacity)//if the flag size is bigger of what the object can handle
    {
        pTemp = (int*)malloc(sizeof(int) * (pBit_flags->capacity + size_of_int));// get temporary dynamic array with new capacity
        if (pTemp == NULL)//if malloc failed
        {
            printf("Could not resize bit flags object");
            return FAILURE;
        }
        else //if malloc worked
        {
            for (i=0; i<pBit_flags->size; i++)
            {
                pTemp[i] = pBit_flags->data[i];//copying the item from the old spot to the new spot created, which is bigger
            }
            free(pBit_flags->data);
            pBit_flags->data = pTemp;
            pBit_flags->capacity += size_of_int;// double its capacity
        }
    }
    index = flag_position / size_of_int;
    if (flag_position >= pBit_flags->size)
	{
		pBit_flags->size = flag_position + 1;
	}
    pBit_flags->data[index] |= (1 << flag_position);// left shifting flag positions away and mixing all the values
    return SUCCESS;

}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    int* pTemp;
    int i;
    int index = 0;
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags; //cast the void* object to a Bit_flag* object
    if (flag_position >= pBit_flags->capacity)//if the flag position is bigger of what the object can handle
    {
        pTemp = (int*)malloc(sizeof(int) * (pBit_flags->capacity + size_of_int));// get temporary dynamic array with new capacity
        if (pTemp == NULL)//if malloc failed
        {
            printf("Could not resize bit flags object");
            return FAILURE;
        }
        else //if malloc worked
        {
            for (i=0; i<pBit_flags->size; i++)
            {
                pTemp[i] = pBit_flags->data[i];//copying the item from the old spot to the new spot created, which is bigger
            }
            free(pBit_flags->data);
            pBit_flags->data = pTemp;
            pBit_flags->capacity += size_of_int;// double its capacity
        }
    }
    index = flag_position / size_of_int;
    if (flag_position >= pBit_flags->size)
	{
		pBit_flags->size = flag_position + 1;
	}
    pBit_flags->data[index] &= ~(1 << flag_position);// left shifting flag positions away and mixing all the values
    return SUCCESS;

}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{
     int bit = 0;
     int index = 0;
    index = flag_position / size_of_int;

     Bit_flags* pBit_flags = (Bit_flags*)hBit_flags; //cast the void* object to a Bit_flag* object

     if (flag_position < 0 || flag_position > pBit_flags->capacity)//checking if the value is out-of-bounds
     {
         bit = -1;
     }
     else
     {
         bit = (pBit_flags->data[index] >> flag_position) & 1;
     }

    return bit;
}

int bit_flags_get_size(BIT_FLAGS hBit_flags)
{
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags; //cast the void* object to a Bit_flag* object
    return pBit_flags->size;
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags)
{
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags; //cast the void* object to a Bit_flag* object
    return pBit_flags->capacity;
}


void bit_flags_destroy(BIT_FLAGS* phBit_flags)
{
    Bit_flags* pBit_flags = (Bit_flags*)phBit_flags; //cast the void* object to a Bit_flag* object
    free(pBit_flags->data);
    free(pBit_flags);//clean up the memory footprint of the object
    *phBit_flags = NULL;
    return;
}

