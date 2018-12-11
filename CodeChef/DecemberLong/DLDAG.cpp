#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
class Node{
public:
	int value;
	int departureTime;
	multiset<int>departureList;
};
class myComparator{
public:
	int operator()(const Node &p1,const Node &p2)
	{
		if(p1.departureTime > p2.departureTime){
			return true;
		}else if(p1.departureTime < p2.departureTime)
		{
			return false;
		}else
		{
			
			int s1 = p1.departureList.size();
			int s2 = p2.departureList.size();
			multiset<int>::iterator itr1 = p1.departureList.begin(),itr2 = p2.departureList.begin();
			if(s1 > s2)
				s1 = s2;
			for(int i=0;i<s1;i++){
				if(*itr1 > *itr2){
					return true;
				}else if(*itr1 < *itr2){
					return false;
				}else{
					itr1++;
					itr2++;
				}
			} 
		}
		return true;
	}
};

Node node[MAX];
void DFS(int index,vector<int>vec[],int departure[],int time){
	if(departure[index] > time)
		return ;
	if(departure[index] < time)
		departure[index] = time;
	for(int i=0;i<vec[index].size();i++)
	{
		DFS(vec[index][i],vec,departure,time+1);
	}
}

bool visited[MAX];
int departure[MAX];
vector<int>vec1[MAX],vec2[MAX];

int main(){
	priority_queue<Node,vector<Node>,myComparator>pq;
	int N,M,A,B;
	freopen("input.txt","r",stdin);
	cin>>N>>M;
	memset(visited,false,sizeof visited);
	for(int i=0;i<M;i++)
	{
		cin>>A>>B;
		vec1[A].push_back(B);
		vec2[B].push_back(A);
	}

	for(int i=1;i<=N;i++)
	{
		if(vec1[i].size() == 0)
			DFS(i,vec2,departure,0);		
	}

	for(int i=1;i<=N;i++){
		node[i].value = i;
		node[i].departureTime = departure[i];
		for(int j=0;j<vec2[i].size();j++){
			(node[i].departureList).insert(departure[vec2[i][j]]);
		}
		if(departure[i] == 0)
			pq.push(node[i]);
	}

	while(!pq.empty()){
		if(pq.size() > 1){
			Node p = pq.top();
			pq.pop();
			Node q = pq.top();
			pq.pop();
			visited[p.value] = true;
			visited[q.value] = true;
			cout<<2<<" "<<p.value<<" "<<q.value<<endl;
			for(int i=0;i<vec2[p.value].size();i++){
				if(!visited[vec2[p.value][i]] && departure[vec2[p.value][i]] == departure[p.value]+1){
					visited[vec2[p.value][i]] = true;
					pq.push(node[vec2[p.value][i]]);
				}
			}

			for(int i=0;i<vec2[q.value].size();i++){
				if(!visited[vec2[q.value][i]] && departure[vec2[q.value][i]] == departure[q.value]+1){
					pq.push(node[vec2[q.value][i]]);
					visited[vec2[q.value][i]] = true;
				}
			}
		}else
		{
			Node p = pq.top();
			pq.pop();
			visited[p.value] = true;
			cout<<1<<" "<<p.value<<endl;
			for(int i=0;i<vec2[p.value].size();i++){
				if(!visited[vec2[p.value][i]] && departure[vec2[p.value][i]] == departure[p.value]+1){
					pq.push(node[vec2[p.value][i]]);
					visited[vec2[p.value][i]] = true;
				}
			}	
		}
	}
	return 0;
}