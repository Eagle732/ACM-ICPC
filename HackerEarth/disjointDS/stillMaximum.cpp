#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define lli long long int
#define MAXX 10000000000
struct Node
{
	lli data;
	lli maxval;
	lli minval;
	lli parent;
	
};

Node tree[MAX];
lli parent[MAX];
bool visited[MAX];

void DFS(vector<lli >vec[],lli node,lli* maxVal,lli* minVal)
{
	if(vec[node].size() == 0)
		return ;
	visited[node] = true;
	lli minv = tree[node].data, maxv = tree[node].data;

	for(int i=0;i<vec[node].size();i++)
	{
		if(visited[vec[node][i]] == false)
		{
			tree[vec[node][i]].parent = node;
			DFS(vec,vec[node][i],maxVal,minVal);
			if(minv > tree[vec[node][i]].minval)
			{
				minv = tree[vec[node][i]].minval;
			}
			if(maxv < tree[vec[node][i]].maxval)
			{
				maxv = tree[vec[node][i]].maxval;
			}
		}
	}
	tree[node].maxval = maxv;
	tree[node].minval = minv;
}
set<lli>cont;
lli findleder(lli index)
{
	if(tree[index].parent == index)
		return index;
	return tree[index].parent;
}

void fixup(vector<lli>vec[],int index){
	lli minv=tree[index].data,maxv=tree[index].data;

	for(int i=0;i<vec[index].size();i++)
	{
		if(vec[index][i] != tree[index].parent)
		{
			if(minv > tree[vec[index][i]].minval)
			{
				minv = tree[vec[index][i]].minval;
			}
			if(maxv < tree[vec[index][i]].maxval)
			{
				maxv = tree[vec[index][i]].maxval;
			}
		}
	}

	tree[index].maxval = maxv;
	tree[index].minval = minv;
	cont.insert(maxv-minv);
	if(tree[index].parent != index){
		fixup(vec,tree[index].parent);
	}
}


int main(){
	freopen("input.txt","r",stdin);
	lli Q,N,arr[MAX][2],A,B;
	cin>>N;
	std::vector<lli> vec[MAX];
	Q = N;
	memset(visited,false,sizeof visited);
	for(int i=1;i<=N-1;i++)
	{
		cin>>A>>B;
		arr[i][0] = A;
		arr[i][1] = B;
		vec[A].push_back(B);
		vec[B].push_back(A);
	}
	
	for(int i=1;i<=N;i++)
	{
		cin>>A;
		tree[i].data = A;
		tree[i].maxval = A;
		tree[i].minval = A;
		tree[i].parent = i;
	}
	lli maxV=0,minV=MAXX;

	DFS(vec,1,&maxV,&minV);
	cont.insert(tree[1].maxval-tree[1].minval);


	for(int i=0;i<N-1;i++)
	{
		cin>>A;
		int a = arr[A][0];
		int b = arr[A][1];
		if(tree[a].parent == b)
		{
			tree[a].parent = a;
			lli leader = findleder(b);
			cont.erase(tree[leader].maxval-tree[leader].minval);
			tree[b].maxval = tree[b].data;
			tree[b].minval = tree[b].data;
			vector<lli>::iterator itr= find(vec[a].begin(),vec[a].end(),b);
			vec[a].erase(itr);
			itr= find(vec[b].begin(),vec[b].end(),a);
			vec[b].erase(itr);
			fixup(vec,b);
			cont.insert(tree[a].maxval - tree[a].minval);

		}else
		{
			tree[b].parent = b;
			lli leader = findleder(a);
			cont.erase(tree[leader].maxval-tree[leader].minval);
			tree[a].maxval = tree[a].data;
			tree[a].minval = tree[a].data;
			vector<lli>::iterator itr= find(vec[b].begin(),vec[b].end(),a);
			vec[b].erase(itr);
			itr= find(vec[a].begin(),vec[a].end(),b);
			vec[a].erase(itr);	
			fixup(vec,a);
			cont.insert(tree[b].maxval - tree[b].minval);
		}
		cout<<*(cont.rbegin())<<endl;
	}
	return 0;
}