#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long int 

using namespace std;
const long long int MAX = 1e6+7;

long long int parent [MAX];
long long int N,M,Cost=0,A,B;
ull K,minCost=0,Weight;
pair<long long int,long long int>PII;
pair<ull,pair<long long int,long long int> >P[MAX];

long long int findRep(long long int x)
{
    while(parent[x] != x)
    {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void uni_on(long long int x,long long int y)
{
    ll a = findRep(x);
    ll b = findRep(y);
    parent[a] = b;
}

void initialize()
{
    for(int i=1;i<=N;i++)
    {
        parent[i] = i;
    }
}



ull kruskalAlgo(pair<ull,pair<ll,ll> > p[])
{
    long long int i=0,num,val=0,val1=0,flag =0;
    
    minCost = 0;
    ull bridges = 0;
    for( i=0;i<M;i++)
    {
        PII = p[i].second;
        
        if(findRep(PII.first) != findRep(PII.second))
        {
            uni_on(PII.first,PII.second);
            minCost += P[i].first;
            bridges++;
        
            if(minCost >K && flag ==0  )
            {
                val = bridges-1;
                flag =1;
            }
            
        }
    }
    // ll num=0;
    for(int i=1;i<=N;i++)
    {
        // cout<<i<<" "<<findRep(i)<<endl;;
        if(findRep(i) != findRep(1)){
            // num++;
            return -1;
        }
    }
    // cout<<"num : "<<num<<endl;
    if(flag == 1)
    return N-1- val;
else return N-1-bridges;

}

int main(){
    freopen("input.txt","r",stdin);
    cin>>N>>M>>K;
    initialize();
    if(K < N-1){
        cout<<-1;
        return 0;
    }
    for(int i=0;i<M;i++)
    {
        cin>>A>>B>>Weight;
        P[i] = make_pair(Weight,make_pair(A,B));
    }
    sort(P,P+M);
    Cost = kruskalAlgo(P);
    cout<<Cost<<endl;
    return 0;
}