#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

int main()
{
	vector<int >vec[100005],vec1[MAX];
	queue<int>Q;
	bool visited[MAX];
	int N,q,level[MAX],A,B,C,numlevel[MAX];
	cin>>N>>q;
	for(int i=1;i<N;i++)
	{
		cin>>A>>B;
		vec[A].push_back(B);
		vec[B].push_back(A);
	}
	Q.push(1);
	level[1] = 0;
	memset(visited,false,sizeof visited);
	memset(numlevel,0,sizeof numlevel);

	visited[1] = true;
	int max_level = 0;
	vec1[0].push_back(1);
	while(!Q.empty())
	{
		int a = Q.front();
		Q.pop();
		for(int i=0;i<vec[a].size();i++)
		{
			if(!visited[vec[a][i]]){		
				Q.push(vec[a][i]);

				level[vec[a][i]] = level[a]+1;
				vec1[level[a]+1].push_back(vec[a][i]);
				// cout<<level[vec[a][i]]<<"  "<<vec[a][i]<<endl;
				visited[vec[a][i]]=true;
			}
		}
		if(max_level < level[a])
		{
			max_level = level[a];
		}
	}
	// cout<<max_level<<endl;
	numlevel[0] = 1;

	for(int i=1;i<=max_level;i++)
	{
		numlevel[i] = numlevel[i-1] + vec1[i].size();
		// cout<<numlevel[i]<<"   "<<vec1[i].size()<<endl;
		// for(int j=0;j<vec1[i].size();j++)
		// {
		// 	cout<<vec1[i][j]<<"---- ";
		// }
		// cout<<endl;
	}

	while(q--)
	{
		cin>>A>>B>>C;
		cout<<level[A]+C<<"   "<<level[A]+B-1<<endl;
		if(level[A]+B-1 < 0){
			
			cout<<numlevel[level[A]+C] - numlevel[level[A]+B]<<endl;
		}
		else{

			cout<<numlevel[level[A]+C] - numlevel[level[A]+B-1]<<endl;
		}
	}



	return 0;
}