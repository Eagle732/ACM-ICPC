#include<bits/stdc++.h>
using namespace std;
#define MAXX 100000
int tree[3*MAXX+5],lazy[3*MAXX+5];

void lazyUpdate(int qs,int qe,int ss,int se,int node)
 {
 	if(lazy[node] != 0)
 	{
 		tree[node] = (se-ss+1) - tree[node];
 		if(ss != se)
 		{
 			lazy[2*node] = 1 - lazy[2*node];
 			lazy[2*node+1] = 1 - lazy[2*node+1];
 		}
 		lazy[node] = 0;
	}
	if(ss > qe || se < qs || ss >se)
 		return ;
 	
	if(qs <= ss && se <= qe)
 	{
 		tree[node] = (se-ss+1) - tree[node];
 		if(ss != se)
 		{
 			lazy[2*node] = 1 - lazy[2*node];
 			lazy[2*node+1] = 1 - lazy[2*node+1];
 		}
 		return; 
 	}
 	int mid = (se+ss)/2;
 	lazyUpdate(qs,qe,ss,mid,2*node);
 	lazyUpdate(qs,qe,mid+1,se,2*node+1);
 	tree[node] = tree[2*node] + tree[2*node+1];

 }

int querySegmentTree(int qs,int qe,int ss,int se,int node)
{
	if(lazy[node] != 0)
	{
		tree[node] = (se-ss+1) -tree[node];
 		if(ss != se)
 		{
 			lazy[2*node] = 1 - lazy[2*node];
 			lazy[2*node+1] = 1 - lazy[2*node+1];
 		}
 		lazy[node] = 0;
	}
	if(qe < ss || qs > se || ss > se)
		return 0;
	if(qs <= ss && se <= qe)
	{
		return tree[node];
	}

	int mid = (se+ss)/2;
 	return (querySegmentTree(qs,qe,ss,mid,2*node)+
 			querySegmentTree(qs,qe,mid+1,se,2*node+1));
}


int main()
{	
	int N,Q,L,R,A; 
	cin>>N>>Q;
	memset(tree,0,sizeof (tree));
	memset(lazy,0,sizeof (lazy));
	for(int i=0;i<Q;i++)
	{
		cin>>A>>L>>R;
		if(A == 0){
			lazyUpdate(L,R,0,N-1,1);
		}
		if(A == 1)
			cout<<querySegmentTree(L,R,0,N-1,1)<<endl;
	}
	return 0;
}