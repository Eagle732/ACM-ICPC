#include<bits/stdc++.h>
using namepace std;
int querySegmentTree(int ss,int se,int qs,int qe,int node)
{
	if(qs <= ss && qe >= se)
		return st[node];
	if(qe < ss || qs > se)
		return 0;
	int mid = ss + (se-ss)/2;
	return querySegmentTree(ss,mid,qs,qe,2*node)+querySegmentTree(mid+1,se,qs,qe,2*node+1);
}

void updateSegmentTree(int ss,int se,int node,int index)
{
	if(node == ss && node se)
	{
		st[node]++;
	}
	int mid = ss + (se-ss)/2;
	if(mid > index)
	{
		updateSegmentTree(ss,mid,2*node,index);
	}else{
		updateSegmentTree(mid+1,se,2*node+1,index);
	}
	st[node] = st[2*node] + st[2*node+1];
}




int main()
{
	int N,arr[MAXX],st[MAXX];
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<N-1;i++)
	{
		cin>>A>>B;
		vec[A].push_back(B);
	}
	dfs();






	return 0;
}