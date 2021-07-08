#include<bits/stdc++.h>
using namespace std;
long long int ara[1000005];
int main(){
    long long int n,l;

    cin>>n;
    for(int i = 0; i < n; i++) cin>>ara[i];
    cin>>l;
    long long int meh = 0,cnt = 0,max = 0,start=0;
    // msf = INT_MIN;
    for(int i = 0; i < n; i++){

            meh = meh + ara[i];
            cnt++;
            if(meh > l){
                meh -= ara[start];
                cnt--;
                start++;
            }
            if(cnt >= max){
              max = cnt;
            }
    }
    cout<<""<<max<<endl;

    //maximum ending here 
}

//another way using sliding 
/*
int largestRange(int ara[],int target){
  int ans = 0;
  int i = 0;
  int j = 0;
  int total = 0;
  int size = sizeof(ara);
  while(j!=size){
    total += ara[j];

    if(total <= target){
      ans = max(ans,j - i + 1);
    }

    while (total > target)
    {
      total-=ara[i++];
    }
    j++;
 
  }
 
  return ans;
}


#include<stdio.h>
#define ll long long
ll maxlen(ll arr[],ll n,ll lar);
int main()
{
    // Write your code here
    ll n,l;
    scanf("%lld",&n);
    ll arr[n+5];
    for(int i=0;i<n;++i){
        scanf("%lld",&arr[i]);
    }
    scanf("%lld",&l);
    printf("%lld",maxlen(arr,n,l));
}

ll maxlen(ll arr[],ll n,ll lar){

    ll len=1,maxl=0,strt=0,end=1;
    ll sum=arr[strt];

    while(end<n){
        sum+=arr[end];
        end++;
        
        if(sum>lar){
            sum-=arr[strt];
            strt++;
            len--;
        }
        len++;
        if(len>maxl) maxl=len;
        
    }
    
return maxl;
}
*/



