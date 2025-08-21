#include<bits/stdc++.h>
using namespace std;

float sqrt_x(int x){
    float low = 0.0;
    float high = x;
    float mid;
    while(high-low>0.000001){
        mid = (low + high)/2;
        if(mid * mid > x){
            high = mid;
        }else{
            low = mid;
        }
    }
    return mid;
}

int main(){

        float x = 20;

        cout<<sqrt_x(x)<<endl;

        return 0;

}
