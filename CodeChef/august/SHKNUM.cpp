#include<bits/stdc++.h>
using namespace std;
unsigned long long int N,T,i,numAdd,p,numSub;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;
		for(i=1;i<=N;i = i<<1);
		p = i>>1;
		i = i>>2;
		for(;i > 0 && (N&i)==0; i = i >> 1);
		if(i != 0){
			numSub = N - p -i;
		}
		else{
			numSub = N >> 2;
		}
		if(N <= 2){
			numSub = 1000;
		}
		// cout<<numSub<<endl;

		if(i == 0){
			numAdd = 1;
		}else if((N&(p>>1)) == 0){
			i = i<<1;
			numAdd = p+i-N;
		}else{
			p = p<<1;
			// cout<<p<<endl<<endl;
			numAdd = p-N+1;
		}
		if(N==1)
		{
			numAdd = 2;
		}
		if(N==0)
		{
			numAdd = 3;
		}
		cout<<min(numSub,numAdd)<<endl;






	}
	return 0;
}