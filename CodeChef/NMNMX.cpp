#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 1000000007
#define left 2*node +1
#define right 2*node +2


ll buildSegmentTree(vector<int>vec,int seg[],int node,int l,int r)
{
	if(l > r)
		return 1;
	if(r == l)
	{
		seg[node] = vec[l];
		return vec[r];
	}

	int mid = l + (r - l)/2;
	ll a = buildSegmentTree(vec,seg,left,l,mid);
	ll b = buildSegmentTree(vec,seg,right,mid+1,r);
	seg[node] = (a*b) % MAX;
	return seg[node];
}

void DP_sol(int arr[],int l,int r,int )
{
	if(l > r)
	{
		return ;
	}
	DP_sol(arr,l+1,r,);
	DP_sol(arr,l,r-1,);




}

int main(){
	int arr[2* 5000 +5],T,a,N,K;
	vector<int>vec;
	cin>>T;
	while(T--)
	{
		cin>>N>>K;
		for(int i=1;i<=N;i++)
		{
			cin>>a;
			vec.push_back(a);
		}
	
		sort(vec.begin(),vec.end());
	
		cout<<buildSegmentTree(vec,arr,0,0,N-1)<<endl;
		for(int i=0;i<2*N+1;i++){
			cout<<arr[i]<<" ";
		}
	}
	return 0;
}