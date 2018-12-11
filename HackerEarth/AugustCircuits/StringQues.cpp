#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
    ll A,B,D,M,X,T,sum,count_t;
    cin>>T;
    while(T--)
    {
        cin>>D>>A>>M>>B>>X;
        X-=D;
        sum = X/((M*A)+B);
        
        X = X% ((M*A)+B);
        count_t = (M+1)*sum;
        // cout<<count_t<<endl;
        count_t += X/A; 
        X = X%A;
        
        // cout<<count_t<<endl;
        X = X%A;
        if(X > 0)
        	count_t++;
        cout<<count_t<<endl;
        
    }
    
    
    
    
    return 0;
}