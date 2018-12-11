#include<bits/stdc++.h>
using namespace std;
#define SIZE 100000 + 1
// Each vertex has all the connected vertices with the edges weights
vector<pair<int,int> >v[SIZE];	
int dist[SIZE];
bool vis[SIZE];

void dijkstra()
{
	// set the vertices distances as infinity	
	// set all vertices as non visited
	memset(vis,false ,sizeof(vis));
	memset(dist,1e4,sizeof dist);
	dist[1] = 0;
	multiset<pair<int,int> >s;		// multiset do the job of min-priority queue

	s.insert({0,1});		// insert the source node with distance = 0
	while(!s.empty())
	{
		pair<int, int>p = *s.begin();
		s.erase(s.begin());
		int x = p.s;
		int 
	}


}




int main()
{





	return 0;
}