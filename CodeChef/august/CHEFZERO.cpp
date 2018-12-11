#include<bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ins(a) insert(a)
#define lli long long int
#define f(a,c,b) for(a=c;a<b;a++)
#define fd(a,c,b) for(a=c;a>=b;a--)
lli SUM=0,MaxSum=0,MINN;
lli A,B,mat[1001][1001];
int res[1001][1001];
int main()
{
	int N,M,K,i,j,xi,yi;
	
	cin>>M>>N>>K;
	f(i,0,M)
	{
		f(j,0,N)
		{
			cin>>mat[i][j];
			res[i][j] = 0;
			SUM += mat[i][j];
		}
	}
	MaxSum = SUM/K;
	SUM=0;
	set<pair<lli,pair<int,int> > >neighbor;
	pair<int,int>pii;
	xi=yi=0;
	int k=0;
	neighbor.ins(mp(mat[0][0],mp(0,0)));
	while(!neighbor.empty() && k <= K)
	{
		SUM=0;
		k++;
		cout<<"First : "<<k<<endl<<endl;
		pair<lli,pair<int,int> > >pii = neighbor.begin();
		for(SUM=0;SUM<MaxSum;)
		{
			if(neighbor.empty())
				break;			
			auto itr = neighbor.begin();
			int xi = (itr->second).first;
			int yi = (itr->second).second;
			res[xi][yi] = k;
			cout<<"xi : "<<xi<<"  yi:"<<yi<<endl;
			neighbor.erase(itr);
			SUM += mat[xi][yi];
			cout<<SUM<<endl;

			if((xi+1 < N) && (res[xi+1][yi] == 0))
				neighbor.ins(mp(mat[xi+1][yi],mp(xi+1,yi)));
			if((yi+1 < M) && (res[xi][yi+1] == 0))
				neighbor.ins(mp(mat[xi][yi+1],mp(xi,yi+1)));
			if((xi-1 >= 0) && (res[xi-1][yi] == 0))
				neighbor.ins(mp(mat[xi-1][yi],mp(xi-1,yi)));
			if((yi-1 >= 0) && (res[xi][yi-1] == 0))
				neighbor.ins(mp(mat[xi][yi-1],mp(xi,yi-1)));			
		}
	}
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}