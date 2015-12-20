#include <stdio.h>
#include <stdlib.h>

void insert(int *arr, int a, int n){ /*0��n-1�����ź���*/
 int i;
 int key = a;

 for(i=0; i<n; i++){
  if(key < arr[i]){
   int j;
   for(j=n-1; j>=i; j--){
    arr[j+1] = arr[j];
   }
   arr[i] = key;
   return;
  }
 }

 arr[n] = key;
 return;
}

void sort(int *arr, int size){
 if(size<2)
  return;
 int i;
 for(i=1; i<size; i++){
  insert(arr, arr[i], i);
 }
}

void main(){
 int i, n, *arr;

 printf("����������Ĵ�С n = ");
 scanf("%d", &n);

 arr = (int*)malloc(sizeof(int)*n);

 printf("������%d������Ԫ�أ�\n", n);
 for(i=0; i<n; i++){
  scanf("%d", &arr[i]);
 }

 printf("������ǰ������Ϊ��");
 for(i=0; i<n; i++){
  printf("%d ", arr[i]);
 }

 printf("\n������������...\n");
 sort(arr, n);

 printf("������������Ϊ��");
 for(i=0; i<n; i++){
  printf("%d ", arr[i]);
 }
 printf("\n");
 free(arr);
}
