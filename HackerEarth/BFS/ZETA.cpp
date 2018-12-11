#include<bits/stdc++.h>
using namespace std;
pair<int,int> fill(pair<int,int>pos,int x,vector<int>vec[],int N,int M)
{
	switch (x)
	{
		case 0:
			if(pos.first == N )
				return make_pair(-1,-1);
			else if(vec[pos.first+1][pos.second] != 10 )
				return make_pair(pos.first+1,pos.second);
			break;
		
		case 1:
			if(pos.first == 1 )
				return make_pair(-1,-1);
			else if(vec[pos.first-1][pos.second] != 10 )
				return make_pair(pos.first-1,pos.second);
			break;
		
		case 2:
			if(pos.second == M )
				return make_pair(-1,-1);
			else if(vec[pos.first][pos.second+1] != 10 )
				return make_pair(pos.first,pos.second+1);
			break;
		
		case 3:
			if(pos.second == 1 )
				return make_pair(-1,-1);
			else if(vec[pos.first][pos.second-1] != 10 )
				return make_pair(pos.first,pos.second-1);
			break;
		
		default:
			return make_pair(-1,-1);
			break;
	}
	return make_pair(-1,-1);
}

int main()
{
	freopen("input.txt","r",stdin);
	int N,M,X,Y,A,Q,Dx,Dy;
	vector<int>vec[10000],res[10000];
	cin>>N>>M;
	cin.ignore();
	string str;
	for(int i=1;i<=N;i++)
	{
		getline(cin,str);
		stringstream ss(str);
		int j = 0;
		vec[i].push_back(0);
		while(ss && j < M)
		{
			char c;
			ss>>c;
			int a;
			if(c != '*')
				a = c-'0';
			else 
				a = 10;
			vec[i].push_back(a);
			res[i].push_back(0);
			j++;

		}
	}
	cin>>X>>Y;
	cin>>Q;

	while(Q--)
	{
		cin>>Dx>>Dy;
		map<pair<int,int>,int> level;
		level.insert(make_pair(make_pair(Dx,Dy),0));
		map<pair<int,int>,pair<pair<int,int>,int> >parent;
		parent.insert(make_pair(make_pair(X,Y),make_pair(make_pair(X,Y),vec[X][Y])));
		
		map<pair<int,int>,bool>visited;

		if(vec[Dx][Dy] == 10){
			cout<<-1<<" "<<-1<<endl;
			continue;
		}
		pair<int ,int >Dest;
		Dest = make_pair(Dx,Dy);
		queue<pair<int,int> >Q;
		Q.push(make_pair(X,Y));
		visited.insert(make_pair(make_pair(X,Y),1));
		int flag = 9999;
		int maxx = 0;
		while(!Q.empty())
		{

			pair<int,int >pos = Q.front();
			Q.pop();
			// cout<<"Pos : "<<pos.first<<" "<<pos.second<<endl;
			
			if(level[pos]>=flag){
				// cout<<"Queue size : "<<Q.size()<<endl;
				continue;
			}
			for(int i=0;i<4;i++)
			{
				pair<int,int>next = fill(pos,i,vec,N,M);
				if(next == make_pair(-1,-1))
					continue;
				if(next == Dest)
				{
					// cout<<level[pos]<<" "<<parent[pos].second + vec[Dx][Dy]<<endl;
					if(maxx < parent[pos].second + vec[Dx][Dy])
						maxx = parent[pos].second + vec[Dx][Dy];
					flag = level[pos]+1;
					continue;
				}
				parent.insert(make_pair(next,make_pair(pos,(parent[pos]).second+vec[next.first][next.second])));
				level[next] = level[pos]+1;
				
				if(visited.count(next) == 0 )
				{
					if(next != Dest)
						visited.insert(make_pair(next,1));
					// else
					// 	visited.insert(make_pair(next,0));
					Q.push(next);
				}
				
			}

		}
		if(flag != 0)
			cout<<flag<<" "<<maxx<<endl;
		else
			cout<<-1<<" "<<-1<<endl;
		
	}
	return 0;
}