#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> // for gettimeofday()
/* Functions */
void bubble_sort(int arr[], int size);
void heap_sort(int arr[], int n);

int main(void)
{
    long seconds, micros;
    int alg_number, quantity, i, j;
    struct timeval start, end;

    printf("Lutfen kullanilacak siralama algoritma numarasini giriniz:\n");
    printf("1. Bubblesort\n2. heap_sort\n3. Insertionsort\n4. Mergesort\n5. Quicksort\n6. Selectionsort\n7. Shellsort\n : ");
    scanf("%d", &alg_number);
    printf("Lutfen siralama veri kumesini giriniz:\n : ");
    scanf("%d", &quantity);

    /* Random array */
    int *arr1 = malloc(quantity * sizeof(int));
    for(i = 0; i < quantity; i++)
    {
    	arr1[i] = rand();
	}
    /* Reverse sorted array */
    j = 0;
    int *arr2 = malloc(quantity * sizeof(int));
    for(i = quantity - 1; i > 0; i--)
    {
    	arr2[j] = i;
        j++;
	}
    /* Sorted array */
    int *arr3 = malloc(quantity * sizeof(int));
    for(i = 0; i < quantity; i++)
    {
    	arr3[i] = i;
	}
/* Just for checking array values
    for (size_t i = 0; i < quantity; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n\n");
    for (size_t i = 0; i < quantity; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n\n");
    for (size_t i = 0; i < quantity; i++)
    {
        printf("%d ", arr3[i]);
    }
*/  


    switch (alg_number)
    {
    case 1:
        gettimeofday(&start, NULL);
            bubble_sort(arr1, quantity);
        gettimeofday(&end, NULL);
        seconds = (end.tv_sec - start.tv_sec);
        micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
        printf("Bubblesort algoritmasi %d random sirali veriyi %d mikrosaniyede siraladi.\n", quantity, micros);
           
        gettimeofday(&start, NULL);
            bubble_sort(arr2, quantity);
        gettimeofday(&end, NULL);
        seconds = (end.tv_sec - start.tv_sec);
        micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
        printf("Bubblesort algoritmasi %d ters sirali veriyi %d mikrosaniyede siraladi.\n", quantity, micros);

        gettimeofday(&start, NULL);
            bubble_sort(arr3, quantity);
        gettimeofday(&end, NULL);
        seconds = (end.tv_sec - start.tv_sec);
        micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
        printf("Bubblesort algoritmasi %d sirali veriyi %d mikrosaniyede siraladi.\n", quantity, micros);
        break;

    

    
    
    default:
        break;
    }

    

    //printf("Yeniden baslamak icin r tusuna, cikmak icin q tusuna basiniz"); 
    

    return 0;
}

void bubble_sort(int arr[], int quantity)
{
 int i, j, t;
    for(i = quantity - 2; i >= 0; i--)
    {
     for(j = 0; j <= i; j++)
      {
        if(arr[j] > arr[j + 1])
           {
              t = arr[j];
              arr[j] = arr[j + 1];
              arr[j + 1] = t;
           }
      }
   }
}

