#include <bits/stdc++.h>
using namespace std;

//Complete the following function.
int HeapInsert(int a[], int n) {
  //Write your code here.
  int temp, i = n;
  temp = a[n];
  while(i > 1 && temp > a[i/2]){
    a[i] = a[i/2];
    i = i/2;
  }
  a[i] = temp;
}
int HeapSort(int ara[],int n){
        int i,j,x,val;
        val = ara[1];
        x = ara[n];
        ara[1] = ara[n];
        ara[n] = val;
        i = 1; j = i*2;
        while(j<n-1){
            if(ara[j+1]>ara[j]){
                j++;
            }
            if(ara[i]<ara[j]){
                swap(ara[i],ara[j]);
                i=j;
                j=2*j;

            }else{
               break;
            }
        }
        return val;
    }

int main() {
    int n,i;
    int arr[1005];
    scanf("%d",&n);
    arr[0] = 0;
    for( i = 1; i <= n; i++){
        scanf("%d",&arr[i]);
    }
    for( i = 2; i <= n; i++){
        HeapInsert(arr,i);
    }
    for( i = n; i > 1; i--){
        HeapSort(arr,i);
    }
    printf("\n");
    for( i=1; i <= n; i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}
