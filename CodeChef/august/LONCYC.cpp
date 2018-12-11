#include<bits/stdc++.h>
using namespace std;
#define MAX 1000007
bool visited[MAX];
vector<int>vec[MAX];
vector<pair<int,int> >edges;
void dfs(vector<int>vec[],int source,string str)
{
	int a,b;
	char ch = source+'0';
	cout<<"Visited : "<<sokurce<<endl;
	// str += ch;
	int len = str.length();
	if(visited[source] == true)
	{
		if(ch == str[len - 2])
			return ;
		else{
			int i=len-1;
			pair<int,int >p = make_pair((int)(str[i]-'0'),(int)(ch-'0'));
				// cout<<p.first<<" "<<p.second<<endl;
				// for(int i=0;i<edges.size();i++)
				// {
				// 	cout<<"ddd : "<<edges[i].first<<" "<<edges[i].second<<endl;
				// }
			if(find(edges.begin(),edges.end(),p) != edges.end() ){
				// cout<<"hoo"<<endl;
				return ;
			}
			while(ch != str[i] && i>0)
			{
				cout<<str[i--];
				a = str[i+1]-'0';
				b = str[i]-'0';
				edges.push_back(make_pair(a,b));
				edges.push_back(make_pair(b,a));
			}
			a = ch-'0';
			b = str[len-1]-'0';
			edges.push_back(make_pair(b,a));
			edges.push_back(make_pair(a,b));
			cout<<ch<<endl;
		}
		return ;
	}

	visited[source] = true;
	for(int i=0;i<vec[source].size();i++)
	{
		char s = '0'+vec[source][i];
		if(str[len-1] != s)
			dfs(vec,vec[source][i],str+ch);
	}
}

int main()
{
	int N,M,T,A,B;
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
		dfs(vec,1,"");
	}



	return 0;
}