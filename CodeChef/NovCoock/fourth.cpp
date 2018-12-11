#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>vec[],int index,int deg[],int* cnt,int val)
{
	cout<<index<<"+++\n";
	if(vec[index].size() == 0 )
		return ;
	deg[index] = val;
	cnt--;
	if(cnt == 0)
		return ;
	for(int i=0;i<vec[index].size();i++)
	{
		if(deg[vec[index][i]] == -1)
		{
			dfs(vec,vec[index][i],deg,cnt,val);
		}
	}
}
int dfs2(vector<int>vec[],int index,int deg[],bool visited[])
{
	if(vec[index].size() == 0)
		return 1;
	visited[index] = true;
	for(int i=0;i<vec[index].size();i++)
	{
		if(visited[vec[index][i]] != true)
		{
			if(abs(deg[index] - deg[vec[index][i]]) == 2)
				return 2;
			return dfs2(vec,vec[index][i],deg,visited);
		}
	}
	return 1;
}
int main(){
	int T,A,B,one,N,zero,two;
	freopen("input.txt","r",stdin);
	cin>>T;
	while(T--)
	{
		bool visited[1000];
		int deg[1000];
		zero = one = two=0;
		vector<int>vec[1000];
		memset(deg,-1,sizeof deg);
		cin>>N;
		for(int i=0;i<N;i++)
		{
			cin>>A;
			if(A == 0){
				zero++;
			}else if(A == 1)
			{
				one++;
			}else
			{
				two++;
			}
		}
		for(int i=0;i<N-1;i++)
		{
			cin>>A>>B;
			vec[A].push_back(B);
			vec[B].push_back(A);
		}
		multimap<int,int>cont;
		for(int i=1;i<=N;i++)
		{
			cont.insert(make_pair(vec[i].size(), i));
		}
		if((zero == N || one == N || two == N)){

			cout<<0<<endl;
			continue;
		}
		else if(zero == 0 && one != 0 && two != 0||zero != 0 && one != 0 && two == 0)
		{
			cout<<1<<endl;
			continue;
		}else if(zero != 0 && one != 0 && two != 0){
			for(multimap<int,int>::reverse_iterator itr = cont.rbegin();itr != cont.rend();itr++)
			{
				if(deg[itr->second] == -1){
				if(one != 0){
					// cout<<itr->second<<" --- "<<endl;
					deg[itr->second] = 1;
					one--;
				}else if(zero != 0 && zero > two)
				{
					dfs(vec,itr->second,deg,&zero,0);
					cout<<endl;
				}else
				{
					dfs(vec,itr->second,deg,&two,2);
				}
			}
			}
			for(int i=0;i<=N;i++)
			{
				cout<<i<<"  "<<deg[i]<<endl;
			}
			memset(visited,false,sizeof visited);
				cout<<dfs2(vec,1,deg,visited)<<endl;
		}
	}
	return 0;
}