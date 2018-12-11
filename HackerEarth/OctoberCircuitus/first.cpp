#include<bits/stdc++.h>
using namespace std;
long long int maxNeg,maxPos;
#define lli long long int
int main()
{
    long long int T,N,a,b;
    cin>>T;
    while(T--)
    {
        cin>>N>>a>>b;
        if(N==1){
        	cout<<3<<endl;
        	continue;
        }
        lli gcd = __gcd(a,b);
        lli w = b/gcd;
        lli h = a/gcd;
        lli a1 = (w*(N-w+2));
        lli a2 = (w*(w-1)/2);
        lli a3 = ((((N+1)/w)-1)*w*h);
        lli a4 = ((N+1)%w);
        
        if(N < w){
     	   cout<<(N+1)*(N+2)/2<<endl;
     	   continue;
    	}

        lli sum=0;
        while(h--)
        {
        	sum += a4--;
        }
       cout<<a1+a2+a3+sum<<endl;
    }
    
    return 0;
}