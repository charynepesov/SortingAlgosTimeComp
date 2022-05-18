#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int[], int);
void swap(int, int);
int[] ArrayMaker(int, int)
void ArrayPrinter(int[], int)


int main(void)
{
    ArrayPrinter(ArrayMaker(1000, 0), 1000);
    

    return 0;
}

void BubbleSort(int[] arr, int n) 
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[i])
            swap(arr[i], arr[j]);
        }        
    }
}

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

int[] ArrayMaker(int number, int type)
{
    int[] arr[number];
    if(type == 0)
    {
        for(int i = 0; i < number; i++)
        {
            arr[i] = i;
        }
    }
    if(type == -1)
    {
        int j = number - 1;
        for(int i = 0; i < number; i++)
        {
            arr[i] = j;
            j--;
        }
    }
    if(type == 1)
    {
        srand(time(0));
        for(int i = 0; i < number; i++)
        {
            arr[i] = rand();
        }
    }
    return arr;
}

void ArrayPrinter(int[] arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }    
}