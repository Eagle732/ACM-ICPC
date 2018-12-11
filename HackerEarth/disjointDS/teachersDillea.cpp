#include<bits/stdc++.h>
using namespace std;
map<int,vector<int> >cont;
#define MAX 100005
int parent[MAX];
int parent_node(int A)
{ 
    if(parent[A] != A)
        return parent_node(parent[A]);
    return A;
}
map<int,int>set_size;

void union_nodes(int A,int B){
    int a = parent_node(A);
    int b = parent_node(B);
    if(a != b){
        if(set_size[b] > set_size[a]){
            parent[a] = parent[b];
            set_size[b] += set_size[a];
            set_size.erase(a);
        }else
        {
            parent[b] = parent[a];
            set_size[a] += set_size[b];
            set_size.erase(b);
            
        }
    }
}
long long int counter_s=1;
int main(){
    freopen("input.txt","r",stdin);
    int N,Q,A,B,arr[100005];
    cin>>N>>Q;
    for(int i=1;i<=N;i++){
        parent[i] = i;
        set_size[i] = 1;
    }
        
    while(Q--)
    {
        cin>>A>>B;
        union_nodes(A,B);
        
    }
    multiset<int>sz;
    for(map<int,int>::iterator itr = set_size.begin();itr != set_size.end();itr++)
        sz.insert(itr->second);
    for(multiset<int>::iterator itr = sz.begin();itr != sz.end();itr++)
            counter_s = (counter_s*(*itr))%1000000007;
    cout<<counter_s;
    return 0;
}