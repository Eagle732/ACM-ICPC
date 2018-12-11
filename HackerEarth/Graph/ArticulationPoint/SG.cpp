#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define lli long long int
set<pair<int,int> >cont;
map<int,bool>ans;
map<pair<int,int>,int >arr;
void DFS(vector<int>vec[],int disc[],int low[],bool visited[],int parent[],int vertex,int tm){
    visited[vertex] = true;
    disc[vertex] = low[vertex] = tm;
    int child = 0;
    for(int i=0;i<vec[vertex].size();i++){

        if(visited[vec[vertex][i]] == false){
            cout<<vertex<<endl;
            DFS(vec,disc,low,visited,parent,vec[vertex][i],tm+1);
        }else if(parent[vertex] != vec[vertex][i]){
        }
    }
    
}
int disc[MAX],low[MAX],parent[MAX],Q,N,M,A,B,C,idx[MAX*10];
bool visited[MAX];
int main()
{
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);;
    
   
    vector<int>vec[MAX];
    cin>>N>>M>>Q;
    for(int i=1;i<=M;i++)
    {
        cin>>A>>B>>C;
        vec[A].push_back(B);
        vec[B].push_back(A);
        arr.insert(make_pair(make_pair(A,B),C));
        arr.insert(make_pair(make_pair(B,A),C));
    }
    memset(visited,false,sizeof visited);
    memset(parent,-1,sizeof parent);
    for(int i=0;i<Q;i++)
    {
        cin>>idx[i];
        ans[idx[i]] = false;
    }
    DFS(vec,disc,low,visited,parent,1,1);

    return 0;
}