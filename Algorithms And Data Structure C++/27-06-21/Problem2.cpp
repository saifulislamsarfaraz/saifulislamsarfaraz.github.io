#include <bits/stdc++.h>
using namespace std;

void selectionSort(int ara[],int n){
    int min,i,j;
    for(i = 0; i < n; i++){
        min  = i;
        for(j = i + 1; j < n; j++){
            if(ara[j] < ara[min]){
                min = j;
            }
        }
        if(i!=min){
        int temp = ara[i];
        ara[i] = ara[min];
        ara[min] = temp;
        }
    }
}
int ara[10005];
int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) cin>>ara[i];
    selectionSort(ara,n);
    for(int i = 0; i < n-1; i++){
        cout<<ara[i]<<" ";
    }
    cout<<ara[n-1]<<endl;


}
