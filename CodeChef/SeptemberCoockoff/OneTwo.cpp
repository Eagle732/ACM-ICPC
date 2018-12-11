#include<bits/stdc++.h>
using namespace std;
#define lli long long int
lli sum=0;
lli T,N,arr[1000000*2+5];
int i,indexx;

int main()
{
	cin>>T;
	
	while(T--)
	{
		cin>>N;
		sum=0;
		indexx=0;
		for(i=1;i<=N;i++)
		{
			cin>>arr[i];
			sum+=arr[i];
			if(arr[i] == 1)
				indexx = i;
		}
		if(arr[1] == 1)
			cout<<sum<<endl;
		else
		{
			cout<<sum-(N-indexx)<<endl;
		}
	}



	return 0;
}