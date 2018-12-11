#include<bits/stdc++.h>
using namespace std;
long long int N,A,arr[100005],res[100005],maxx=0;
	
int main()
{
	cin>>N;
	memset(arr,0,sizeof arr);
	while(N--)
	{
		cin>>A;
		if(maxx < A)
			maxx = A;
		arr[A]++;
	}
	res[0]=0;
	res[1] = arr[1];
	for(int i=2;i<=maxx;i++)
	{
		res[i] = max(res[i-1],res[i-2]+(arr[i]*i));
	}
	cout<<res[maxx];



	return 0;
}