#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MAXX 100005
lli tree[MAXX],lazy[MAXX];
int T,N;
void lazyUpdate(int ss,int se,int qs,int qe,int node)
{
    if(lazy[node] != 0)
    {
        tree[node] += 1;
        if(ss != se)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(ss > se || ss > qe || se < qs)
        return ;
    
    if(ss >= qs && se <= qe)
    {
        tree[node] += (se-ss+1);
        if(ss != se)
        {
            lazy[node*2] += 1;
            lazy[node*2+1] += 1;
        }
        return ;
    }
    int mid = (qs+pe)/2;
    lazyUpdate(ss,mid,qs,qe,2*node);
    lazyUpdate(mid+1,se,qs,qe,2*node+1);
    tree[node] = max(tree[2*node],tree[2*node+1]);
    return ;
}

lli query(int ss,int se,int qs,int qe,int node)
{
    if(lazy[node] != 0)
    {
        tree[node] += 1;
        if(ss != se)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(ss > se || ss > qe || se < qs)
        return 0;
    if(ss >= qs && se <= qe)
        return tree[node];
        
    int mid = (qs+pe)/2;
    return max(query(ss,mid,qs,qe,2*node),query(mid+1,se,qs,qe,2*node+1));
}

int main()
{
    cin>>T;
    while(T--)
    {
        memset(lazy,0,sizeof lazy);
        memset(tree,0,sizeof tree);
    
        cin>>N;
        for(int i=0;i<N;i++)
        {
            cin>>A>>B;
            lazyUpdate(A,B-1,1,N,1);
        }
        cout<<query(1,N,1,N,1);
    }
    
    
    
    
    
    
    
    return 0;
}