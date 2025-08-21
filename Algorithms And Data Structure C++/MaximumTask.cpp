#include<bits/stdc++.h>
using namespace std;
int ara[1005][1005];
typedef struct value{
	int start;
	int end;
}data;
bool compare(data a, data b){
    if(a.end<b.end){
        return 1;
    }else{
    return 0;
    }
}
int main(){
        int n;
        cin>>n;

        data array[n+5];

        for(int i = 0; i <n; i++){
            cin>>array[i].start;
            cin>>array[i].end;
        }
        sort(array,array+n,compare);
//        for(int i = 0; i < n; i++){
//            cout<<array[i].start<<" ";
//            cout<<array[i].end<<endl;
//        }

        int last = 0;
        int cnt = 1;

        for(int i= 0; i < n; i++){
            if(array[i].start>=array[last].end){
                cnt++;
                last = i;
            }
        }
        cout<<cnt<<endl;

}
