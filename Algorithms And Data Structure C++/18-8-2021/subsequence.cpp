#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
int max = INT_MIN;
int func(char sA[],int arrsize,char sub[],int subsize,int index,char sB[])
{


    for(int i =0; i<=subsize; i++){
            cout<<sub[i];
        }
        printf("\n");
    for(int i=index; i<arrsize; i++)
    {
        sub[subsize]=sA[i];
        subsize++;
        func(sA,arrsize,sub,subsize,i+1,sB);
        subsize--;
    }
    return -1;

}
 char sub[30000000];
int main()
{
    string a,b;
    cin>>a;
    cin>>b;
    char sA[a.length()+1];
    strcpy(sA,a.c_str());

    char sB[b.length()+1];
    strcpy(sB,b.c_str());



    int cnt = func(sA,a.length(),sub,0,0,sB);


        cout<<""<<cnt<<endl;

}
