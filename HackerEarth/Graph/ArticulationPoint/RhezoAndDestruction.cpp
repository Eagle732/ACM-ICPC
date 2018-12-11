#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
#define lli long long int
// bool AP[MAX];
void dfs(vector<int>vec[],int disc[],int low[],bool visited[],int parent[],bool AP[],int vertex,int time){
	visited[vertex] = true;
	disc[vertex] = low[vertex] = time;
	int child = 0;
	for(int i=0;i<vec[vertex].size();i++)
	{
		// cout<<"G";
		if(visited[vec[vertex][i]] == false)
		{
			// cout<<"hello";
			child ++;
			parent[vec[vertex][i]] = vertex;
			dfs(vec,disc,low,visited,parent,AP,vec[vertex][i],time+1);
			low[vertex] = min(low[vertex],low[vec[vertex][i]]);

			if(parent[vertex] == -1 and child > 1){
				AP[vertex] = true;
			}
			if(parent[vertex] != -1 and low[vec[vertex][i]] >= disc[vertex])
			{
				AP[vertex] = true;
			}
		}else if(parent[vertex] != vec[vertex][i])
		{
			low[vertex] = min(low[vertex],disc[vec[vertex][i]]);
		}
	}
}

int main(){
	// freopen("input.txt","r",stdin);
	vector<int>vec[MAX];
	int disc[MAX],low[MAX],parent[MAX];
	bool AP[MAX],visited[MAX];
	memset(visited,false,sizeof visited);
	memset(parent,-1,sizeof parent);
	int N,T,Q,A,B,M;
	cin>>N>>M;
	for(int i=0;i<M;i++)
	{
		cin>>A>>B;
		vec[A].push_back(B);
		vec[B].push_back(A);
	}
	for(int i=1;i<=N;i++)
		if(visited[i] == false)
			dfs(vec,disc,low,visited,parent,AP,i,1);
	cin>>Q;
	while(Q--)
	{
		cin>>A;
		if(AP[A] == true)
		{
			cout<<"Satisfied "<<vec[A].size()<<endl;
		}else
		{
			cout<<"Not Satisfied\n";
		}
	}
	return 0;
}