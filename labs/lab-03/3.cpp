#include<bits/stdc++.h>
using namespace std;

    long long int  Start[1000005];
    long long int Finish[1000005];
    
int main(){

   int act;
   scanf("%d",&act);
   for(int p=0;p<act;p++)
   {
       scanf("%lld",&Start[p]);
       scanf("%lld",&Finish[p]);
   }
   long long int i, j,cnt=1;
   
   i = 0;
   for (j = 1; j < act; j++){
      if (Start[j] >= Finish[i]){
      	
         cnt++;
         i = j;
      }
   }
   printf("%lld",cnt);
   return 0;
}
