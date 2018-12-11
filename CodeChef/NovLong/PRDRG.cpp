#include<bits/stdc++.h>
using namespace std;
long long int T,A,num=30,arr[35][2];
void folding()
{
	
	
	arr[0][0] = 0;
	arr[0][1] = 1;
	arr[1][0] = 1;
	arr[1][1] = 2;
	int i=1;
	while(i++<num)
	{
		arr[i][1] = 2*max(arr[i-1][1],arr[i-2][1]);
		arr[i][0] = 2*min(arr[i-1][0],arr[i-2][0]) + max(arr[i-1][0],arr[i-2][0]); 
	}

}
int main()
{
	cin>>T;
	folding();
	while(T--)
	{
		cin>>A;
		cout<<arr[A][0]<<" "<<arr[A][1]<<" ";
	}
	

	return 0;
}
