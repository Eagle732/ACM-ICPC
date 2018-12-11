#include<bits/stdc++.h>
using namespace std;
#define MAXX 100005
#define lli long long
#define MAX 1000000009
lli tree[3*MAXX],arr[MAXX],lazy[3*MAXX];
void update(int ss,int se,int node,int x)
{
	if(lazy[node] != 0)
	{
		tree[node] -= lazy[node];
		if(ss != se)
		{
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(ss > se )
		return;
	if(ss == se)
	{
		if(tree[node] > x)
		{
			tree[node] -= 1;
		}
		return ;
	}
	
	if(tree[node] > x)
	{
		tree[node] -= 1;
		if(ss != se)
		{
			lazy[2*node] += 1;
			lazy[2*node+1] += 1;
		}
	}else
	{
		int mid = (ss+se)/2;
		update(ss,mid,2*node,x);
		update(mid+1,se,2*node+1,x);
		tree[node] = min(tree[2*node],tree[2*node+1]);
	}	
}
void printRes(int ss,int se,int node)
{
	if(ss == se){
		// cout<<ss<<"  "<<se<<endl;
		cout<<tree[node]<<" ";
		return ;
	}
	if(ss > se)
		return ;
	int mid = (ss+se)/2;
	printRes(ss,mid,2*node);
	printRes(mid+1,se,2*node+1);
}
void buildTree(int ss,int se,int node)
{
	if(ss > se)
		return ;
	if(ss == se){
		tree[node] = arr[ss];
		return ;
	}
	int mid = (ss+se)/2;
	buildTree(ss,mid,2*node);
	buildTree(mid+1,se,2*node+1);

	tree[node] = min(tree[2*node],tree[2*node+1]);
	return ;	
}
int main()
{
	int N,Q,X;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>arr[i];
	}
	buildTree(0,N-1,1);
	// printRes(0,N-1,1);
	// for(int i=0;i<2*N;i++)
	// 	cout<<tree[i]<<" ";
	cin>>Q;
	for(int i=0;i<Q;i++)
	{
		cin>>X;
		update(0,N-1,1,X);

	}
	update(0,N-1,1,MAX);

		printRes(0,N-1,1);

	return 0;
}