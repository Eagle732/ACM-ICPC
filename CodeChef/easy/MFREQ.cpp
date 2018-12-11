#include<bits/stdc++.h>
using namespace std;
#define MAXX 100005
int main()
{
	long long int N,M,arr[MAXX],K,L,R,arrc[MAXX],arrb[MAXX],l,r;
	cin>>N>>M;
	for(int i=1;i<=N;i++)
	{
		cin>>arr[i];
		if(i>1){
			if(arr[i] == arr[i-1])
			{
				arrb[i] = arrb[i-1];
			}else
			{
				arrb[i] = i;
			}
		}else{
			arrb[i] = 1;
		}
	}
	arrc[N] = N;
	for(int i=N-1;i>0;i--)
	{
		if(arr[i+1] == arr[i])
		{
			arrc[i] = arrc[i+1];
		}else
		{
			arrc[i] = i;
		}
	}

	
	for(int i=0;i<M;i++)
	{
		cin>>L>>R>>K;
		if((R-L)%2==0)
		{
			int mid = L+(R-L)/2;
			int l = arrb[mid];
			int r = arrc[mid];
			if(l < L) l = L;
			if(r > R) r = R;
			if(r-l+1 >= K)
				cout<<arr[mid]<<endl;
			else
				cout<<-1<<endl;
		}else
		{
			int mid1 = L+(R-L)/2;
			int mid2 = mid1+1;
			if(arr[mid1] != arr[mid2])
			{
				cout<<-1<<endl;
			}else
			{
				int mid = L + (R-L)/2;
				int l = arrb[mid],r = arrc[mid];
				if(l < L) l = L;
				if(r > R) r = R;
				if(r-l+1 >= K)
					cout<<arr[mid]<<endl;
				else
					cout<<-1<<endl;
				}
		}
	}
	
	return 0;
}