#include<bits/stdc++.h>
using namespace std;
#define MAX 100000

int parent[MAX];
int color[MAX];
vector<int>vec[MAX];
int T,M,N,A,B;
bool CYC[MAX],visited[MAX];

void printParent(int parent[],int a,int b)
{
	if(a == b)
	{
		cout<<b<<"    "<<endl;
		CYC[b] = true;
		return ;
	}
	else{
		cout<<a<<"    ";
		CYC[a] = true;
		printParent(parent,parent[a],b);
		return ;
	}
}

void DFS(vector<int>vec[],int source,int parent[])
{
	if(color[source] == 2)						// Node is Black colored and hence it is already visited
	{
		return ;
	}

	if(color[source] == 0)
	{
		color[source] = 1;
		for(int i=0;i<vec[source].size();i++){
			if(color[vec[source][i]] == 1)
			{
				if(parent[source] != vec[source][i])
					printParent(parent,source,vec[source][i]);
				continue;
			}
			parent[vec[source][i]] = source;
			// color[vec[source][i]] = 1;
			DFS(vec,vec[source][i],parent);
			color[vec[source][i]] = 2;
		}
		
	}
}
bool isPresent(int a)
{
	return CYC[a];
}

int dfsPart2(vector<int>vec[],int source,int cycle)
{
	int counter = 1;
	if(isPresent(source) && cycle == 0)
	{
		return 1;
	}
	if(visited[source])
		return 0;
	visited[source] = true;
	for(int i=0;i<vec[source].size();i++)
	{
		if(isPresent(vec[source][i]) && cycle != 0)
		{
			counter += dfsPart2(vec,vec[source][i],cycle-1);

		}else
		{
			counter += dfsPart2(vec,vec[source][i],cycle);
		}
	}
	cout<<source<<" "<<counter<<endl;
	return counter;
}




int main()
{
	freopen("input.txt","r",stdin);
	for(int i=0;i<MAX;i++)
	{
		parent[i] = i;
		color[i] = 0;
		CYC[i] = false;
		visited[i] = false;
	}
	cin>>T;
	while(T--)
	{
		cin>>N>>M;
		for(int i=0;i<M;i++)
		{
			cin>>A>>B;
			vec[A].push_back(B);
			vec[B].push_back(A);
		}
		DFS(vec,12,parent);
		// for(int i=1;i<=N;i++)
		cout<<dfsPart2(vec,18,2)<<endl;

	}



	return 0;
}