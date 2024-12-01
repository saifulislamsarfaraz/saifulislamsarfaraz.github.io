#include <bits/stdc++.h>

using namespace std;

void heapSort(int a[], int n) {
  //Write your code here.
  int temp, i = n;
  temp = a[n];
  while(i!=1 && temp > a[i/2]){
    a[i] = a[i/2];
    i = i/2;
  }
  a[i] = temp;

}
int main(){

int size=5;
int i;
int array[size]; // array of size=5;

for(i=0;i<size;i++){
   scanf("%d",&array[i]);
                }

    heapSort(array,size);
    for(i=0 ; i<size ; i++){
	printf("%d", array[i]) ;
}

return 0;

}
