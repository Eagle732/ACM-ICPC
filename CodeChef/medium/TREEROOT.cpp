#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,N,A,B;
	long long int sum,sum1;
	cin>>T;
	while(T--)
	{
		cin>>N;
		sum=0;sum1=0;
		while(N--)
		{
			cin>>A>>B;
			sum+=A;
			sum1+=B;
		}
		cout<<sum-sum1<<endl;
	}
	return 0;
}