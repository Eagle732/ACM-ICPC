#include<bits/stdc++.h>
using namespace std;
#define pr make_pair(-1,-1)
map<pair<int,int >,bool >visited;

pair<int,int> isAdjacent(vector<int> vec[],int i,pair<int,int>p,int M,int N)
{
	pair<int,int>p1;
	if(i == 0){
		p1 = make_pair(p.first - 1,p.second - 1);
	}else if (i==1)
	{
		p1 = make_pair(p.first -1,p.second );
	}else if (i==2)
	{
		p1 = make_pair(p.first -1,p.second + 1);
	}else if (i==3)
	{
		p1 = make_pair(p.first ,p.second -1);
	}else if (i==4)
	{
		p1 = make_pair(p.first ,p.second +1);
	}else if (i==5)
	{
		p1 = make_pair(p.first+1 ,p.second - 1);
	}else if (i==6)
	{
		p1 = make_pair(p.first +1,p.second );
	}else if (i==7)
	{
		p1 = make_pair(p.first + 1,p.second + 1);
	}
	
	if(p1.first>=1 && p1.second >=1 && p1.first <= M && p1.second <= N)
	{
		if(vec[p1.first][p1.second] == 1){
			vec[p1.first][p1.second] = 0;
			return p1;

		}
	}
	return make_pair(-1,-1);
	
}


int main(){
	// freopen("input.txt","w",stdin);
	int T,M,N,A,count_t,maxGroup,totalGroup,Group,arr[12][2];
	cin>>T;
	for(int h=0;h<T;h++){
	
	cin>>M>>N;
	vector<int>vec[M+2];
	for(int i=1;i<=M;i++){
		vec[i].push_back(0);
		for(int j=1;j<=N;j++){
			cin>>A;
			vec[i].push_back(A);
		}
	}
	queue<pair<int,int> >Q;
	pair<int,int> q,p1;
	totalGroup = maxGroup = 0;
	for(int i=1;i<=M;i++)
	{	 
		for(int j=1;j<=N;j++)
		{
			Group=1;
			if(vec[i][j]==1)
			{
				Q.push(make_pair(i,j));
				while(!Q.empty())
				{
					q = Q.front();
					Q.pop();
					vec[q.first][q.second] = 0;
					for(int k=0;k<8;k++)
					{
						p1 = isAdjacent(vec,k,q,M,N);
						if(p1.first != -1){
							Q.push(p1);
							Group++;
						}
					}
				}

				if(Group>maxGroup){
					maxGroup = Group;
				}
				Group=0;
				totalGroup++;
			}
		}
	}
		// cout<<totalGroup<<" "<<maxGroup<<endl;
		arr[h][0] = totalGroup;
		arr[h][1] = maxGroup;
		totalGroup = 0;
		maxGroup = 0;
	}
	for(int i=0;i<T;i++)
		cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
	return 0;

}