#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long T,N,K,arr[1000],counter;

	cin>>T;
	while(T--)
	{
		counter = 0;
		cin>>N>>K;
		long long  prev = 0;
		for(int i=0;i<N;i++)
		{
			cin>>arr[i];
			if((arr[i]-prev)%K == 0)
			{
				counter += (((arr[i]-prev)/K)-1);
				prev = arr[i];
			}else
			{
				counter += ((arr[i]-prev)/K);
				prev = arr[i];
			}

		}
		cout<<counter<<endl;
	}
	return 0;
}