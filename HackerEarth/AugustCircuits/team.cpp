#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100000

map<int,ll>minMap,maxMap;
multimap<ll,pair<int,int> >weight;

bool visited[MAX];
ll RankNode[MAX];

ll min(ll a,ll b)
{
    return a>b?b:a;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}

void dfs(vector<int>vec[], int source)
{
    if(vec[source].size() == 0)
    {
        minMap[source] = RankNode[source];
        maxMap[source]= RankNode[source];
        return ;
    }
    ll penalty;
    minMap[source] = 1e10;
    maxMap[source] = 0;

    for(int i=0;i<vec[source].size();i++)
    {
        dfs(vec,vec[source][i]);
        minMap[source] = min( minMap[source], minMap[ vec[source][i]] );
        maxMap[source] = max( maxMap[source], maxMap[ vec[source][i]] );
        
        penalty = max(abs(RankNode[source] - minMap[vec[source][i]] ), abs(RankNode[source] - minMap[vec[source][i]] ));
    
        weight.insert(pair<ll,pair<int,int> >(penalty, make_pair(source,vec[source][i])));
    }
}

void DFS(vector<int>tree[],int source)
{
    
    if(tree[source].size() == 0)
        return ;
    
    if(visited[source])
        return ;

    visited[source] = true;

    for(int i=0;i<tree[source].size();i++)
    {
        DFS(tree,tree[source][i]);
        visited[tree[source][i]] = true;
    }
}


int main()
{
    int T,N,K,root,A,B;
    cin>>T;
    while(T--)
    {
        vector<int>tree[MAX];   
        cin>>N>>K;
        for(int i=1;i<=N;i++)
        {
            cin>>RankNode[i];
        }

        for(int i=0;i<N-1;i++)
        {
            cin>>A>>B;
            tree[A].push_back(B);
        }
        
        memset(visited,false,sizeof(visited));
        minMap.clear();
        maxMap.clear();
        weight.clear();
        
        for(int i=1;i<=N;i++)
        {
            // cout<<"Hello";
            if(!visited[i]){
                root = i;
                DFS(tree,i);
            }
        }
        cout<<root<<endl;
        dfs(tree,root);
        // K--;
        for(auto i = weight.rbegin(); i != weight.rend(); i++)
        {
            K--;
            if(K==0)
                cout<<i->first<<endl;
            // cout<<i->first<<"   "<<(i->second).first<<"    "<<(i->second).second<<endl;
        }
        // cout<<weight.size();
    }
    
    
    
    
    
    return 0;
}