#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 5;
int parent[MAX];
int edges,nodes;
pair<long long,pair<int,int> >p[MAX];
int findRep(int X)
{
	while(parent[X] != X)
	{
		parent[X] = parent[parent[X]];
		X = parent[X];
	}
	return X;
}

void uni_on(int X,int Y)
{
	int X_rep = findRep(X);
	int Y_Rep = findRep(Y);
	parent[X_rep] = Y_Rep;
}

void initialize()
{
	for(int i=0;i<edges;i++)
	{
		parent[i] = i;
 	}
}

long long kruskal(pair<long long,pair<int,int> >p[])
{
	int x,y;
	long long cost,minimumCost=0;
	for(int i=0;i<edges;i++)
	{
		x = p[i].second.first;
		y = p[i].second.second;
		cost = p[i].first;
		if(findRep(x) != findRep(y))
		{
			uni_on(x,y);
			minimumCost += cost;
		}
	}
	return minimumCost;
}

int main()
{
	int u,v;
	long long weight,cost,minimumCost=0,N;
	cin>>edges;
	initialize();
	for(int i=0;i<edges;i++)
	{
		cin>>u>>v>>weight;
		p[i] = make_pair(weight,make_pair(u,v));
	}
	sort(p,p+edges);
	minimumCost = kruskal(p);
	cout<<minimumCost<<endl;

	return 0;
}