#include<bits/stdc++.h>
using namespace std;
long long int maxx=1,a,count_t=1;
#define MAX 100005
long long int arr[MAX];
int main()
{
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>arr[i];
	}

	for(int i=a-1; i > 0; i--)
	{
		if(arr[i] - arr[i-1] >= 0)
		{
			count_t++;
		}
		else
		{
			count_t = 1;
		}
		if(maxx < count_t)
		{
			maxx = count_t;
		}

	}
	cout<<maxx;




	return 0;
}