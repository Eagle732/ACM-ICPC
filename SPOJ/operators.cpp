#include<bits/stdc++.h>
using namespace std;
#define MAXX 100
#define lli long long int
lli arr[200],K;
int main()
{
	int N;	
	cin>>N>>K;
	for(int i=0;i<N;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+N);
	for(int i=0;i<N;i++)
	{
		cout<<arr[i]<<" ";
	}






	return 0;
}