#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> // for gettimeofday()
/* Functions */
void bubble_sort(int arr[], int size);
void heap_sort(int arr[], int n);
void insertion_sort(int *p, int size);
void mergeSort(int arr[], int l, int r);

int main(void)
{
    clock_t begin, end;
    double time_spent;
    int alg_number, quantity, i, j;
    

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
        begin = clock();
            bubble_sort(arr1, quantity);
        end = clock();
        time_spent = (double)(1000 * (end - begin)/CLOCKS_PER_SEC);
        printf("Bubblesort algoritmasi %d random sirali diziyi %lf millisaniyede siraladi.\n", quantity, time_spent);
           
        begin = clock();
            bubble_sort(arr2, quantity);
        end = clock();
        time_spent = (double)(1000 * (end - begin)/CLOCKS_PER_SEC);
        printf("Bubblesort algoritmasi %d ters sirali diziyi %lf millisaniyede siraladi.\n", quantity, time_spent);

        begin = clock();
            bubble_sort(arr3, quantity);
        end = clock();
        time_spent = (double)(1000 * (end - begin)/CLOCKS_PER_SEC);
        printf("Bubblesort algoritmasi %d sirali diziyi %lf millisaniyede siraladi.\n", quantity, time_spent);
        break;

    case 2:
        begin = clock();
            heap_sort(arr1, quantity);
        end = clock();
        time_spent = (double)(1000 * (end - begin)/CLOCKS_PER_SEC);
        printf("Heapsort algoritmasi %d random sirali diziyi %lf millisaniyede siraladi.\n", quantity, time_spent);
           
        begin = clock();
            heap_sort(arr2, quantity);
        end = clock();
        time_spent = (double)(1000 * (end - begin)/CLOCKS_PER_SEC);
        printf("Heapsort algoritmasi %d ters sirali diziyi %lf millisaniyede siraladi.\n", quantity, time_spent);

        begin = clock();
            heap_sort(arr3, quantity);
        end = clock();
        time_spent = (double)(1000 * (end - begin)/CLOCKS_PER_SEC);
        printf("Heapsort algoritmasi %d sirali diziyi %lf millisaniyede siraladi.\n", quantity, time_spent);
        break;
    
    case 3:
        begin = clock();
            insertion_sort(arr1, quantity);
        end = clock();
        time_spent = (double)(1000 * (end - begin)/CLOCKS_PER_SEC);
        printf("Insertionsort algoritmasi %d random sirali diziyi %lf millisaniyede siraladi.\n", quantity, time_spent);
           
        begin = clock();
            insertion_sort(arr2, quantity);
        end = clock();
        time_spent = (double)(1000 * (end - begin)/CLOCKS_PER_SEC);
        printf("Insertionsort algoritmasi %d ters sirali diziyi %lf millisaniyede siraladi.\n", quantity, time_spent);

        begin = clock();
            insertion_sort(arr3, quantity);
        end = clock();
        time_spent = (double)(1000 * (end - begin)/CLOCKS_PER_SEC);
        printf("Insertionsort algoritmasi %d sirali diziyi %lf millisaniyede siraladi.\n", quantity, time_spent);
        break;

    case 4:
        begin = clock();
            mergeSort(arr1, 0, quantity);
        end = clock();
        time_spent = (double)(1000 * (end - begin)/CLOCKS_PER_SEC);
        printf("Mergesort algoritmasi %d random sirali diziyi %lf millisaniyede siraladi.\n", quantity, time_spent);
           
        begin = clock();
            mergeSort(arr2, 0, quantity);
        end = clock();
        time_spent = (double)(1000 * (end - begin)/CLOCKS_PER_SEC);
        printf("Mergesort algoritmasi %d ters sirali diziyi %lf millisaniyede siraladi.\n", quantity, time_spent);

        begin = clock();
            mergeSort(arr3, 0, quantity);
        end = clock();
        time_spent = (double)(1000 * (end - begin)/CLOCKS_PER_SEC);
        printf("Mergesort algoritmasi %d sirali diziyi %lf millisaniyede siraladi.\n", quantity, time_spent);
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

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void heapify(int arr[], int n, int i)
{
    int max = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    if (leftChild < n && arr[leftChild] > arr[max])
      max = leftChild;

    if (rightChild < n && arr[rightChild] > arr[max])
      max = rightChild;

    if (max != i) {
      swap(&arr[i], &arr[max]);
      heapify(arr, n, max);
    }
}

void heap_sort(int arr[], int n)
{
	int i;
    for (i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
    for (i = n - 1; i >= 0; i--)
	{
      swap(&arr[0], &arr[i]);
      heapify(arr, i, 0);
    }
}

void insertion_sort(int *p, int size)
{
   int i,j,t;

   for (i = 0; ++i < size; ) {
      t = p[i];
      for (j = i; p[j - 1] > t; ) {
         p[j] = p[j - 1];
            if (--j <= 0)
              break;
      }
      p[j] = t;
   }
}

void merge(int arr[], int p, int q, int r)
{
  int n1 = q - p + 1;
  int n2 = r - q;
  int i;
  int L[n1], M[n2];
  int j;
  for (i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];
  int k;
  i = 0;
  j = 0;
  k = p;
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}