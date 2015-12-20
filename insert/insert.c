#include <stdio.h>
#include <stdlib.h>

void insert(int *arr, int a, int n){ /*0到n-1都已排好序*/
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

 printf("请输入数组的大小 n = ");
 scanf("%d", &n);

 arr = (int*)malloc(sizeof(int)*n);

 printf("请输入%d个数组元素：\n", n);
 for(i=0; i<n; i++){
  scanf("%d", &arr[i]);
 }

 printf("在排序前，数组为：");
 for(i=0; i<n; i++){
  printf("%d ", arr[i]);
 }

 printf("\n调用排序函数中...\n");
 sort(arr, n);

 printf("在排序后，数组变为：");
 for(i=0; i<n; i++){
  printf("%d ", arr[i]);
 }
 printf("\n");
 free(arr);
}
