#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
void merge(int arr[], int l, int m, int r) {
   int i, j, k;
   int n1 = m - l + 1;
   int n2 = r - m;
   int L[50], R[50];
   L[n1]=32767;
   R[n2]=32767;
   for (i = 0; i < n1; i++)
      L[i] = arr[l + i];
   for (j = 0; j < n2; j++)
      R[j] = arr[m + 1+ j];
   i = 0, j = 0, k = l;
   while (i < n1 && j < n2) {
      if (L[i] <= R[j]) {
         arr[k] = L[i];
         i++;
      } else {
         arr[k] = R[j];
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
      arr[k] = R[j];
      j++;
      k++;
   }
}
void iterativeMergeSort(int arr[], int l, int r) {
   if (l < r){
      int mid = l+(r-l)/2;
      iterativeMergeSort(arr, l, mid);
      iterativeMergeSort(arr, mid+1, r);
      merge(arr, l, mid, r);
   }
}
void main()
{  clrscr();
   int arr[100] ,size,i;
   printf("enter the size of array");
   scanf("%d",&size);
printf("\n enter the array elements:");
   for (i=0; i<size; i++)
      {scanf("%d",&arr[i]);
      }
   iterativeMergeSort(arr, 0, size - 1);
   printf("\nSorted array : \t");
   for (i=0; i < size; i++)
     { printf("%d\t",arr[i]);
     }
     getch();
}