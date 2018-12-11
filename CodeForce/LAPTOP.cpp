#include<bits/stdc++.h>
using namespace std;
int main()
{

	int N,n,A,B,arr[100005],flag=0;
	cin>>n;
	N=n-1;
	while(n--)
	{
		cin>>A>>B;
		arr[A]=B;
	}
	while(N)
	{
		// cout<<arr[N+1]<<"  "<<arr[N]<<endl;
		if(arr[N+1]<arr[N])
		{
			cout<<"Happy Alex";
			flag =1;
			break;
		}
		N--;
	}
	if(flag == 0)
		cout<<"Poor Alex";





	return 0;
}