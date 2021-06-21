#include <bits/stdc++.h>
using namespace std;

int binarySearch(int ara[],int value){
    int start = 0;
    int end = sizeof(ara);
    while (start<end)
    {
        int mid = (start + end) /2;
        if(ara[mid]==value){
            return mid;
        }else if(ara[mid]<value){
            start = mid + 1;
        }else{
            end = mid;
        }
    }
    return -1;


}

int main(){
    int n,q;
    int ara[1005];
    cin>>n>>q;
    for(int i=0; i < n; i++){
        cin>>ara[i];
    }

    for(int i=0; i<q; i++){
        int contains;
        cin>>contains;
        int a = binarySearch(ara,contains);
        cout<<""<<a<<endl;
    }
    return 0;
}
