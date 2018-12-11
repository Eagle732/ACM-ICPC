#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int table[60][60];
int func(int arr[],int l,int r,int M)
{

	if(r-l < M){
		return arr[r]-arr[l];
	}
	
	if(table[l][r] != -1)
		return table[l][r];

	table[l][r] = min(func(arr,l,r-1,M),func(arr,l+1,r,M));
	return table[l][r];
	
}
int main()
{
	memset(table,-1,sizeof(table));
	int M,N,arr[MAX];
	cin>>M>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>arr[i];
	}
	sort(arr+1,arr+N+1);
	// for(int i=1;i<=N;i++)cout<<arr[i]<<endl;
	int l=1; int r=N;
	cout<<func(arr,l,r,M)<<endl;
	return 0;
}