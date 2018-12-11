#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define ll long long int
ll tree[2*MAX+5];
ll buildSegmentTree(ll arr[],int l,int r,int node)
{
    if(l == r)
    {
        tree[node] = arr[l];
        return tree[node];
    }
    int left = 2*node;
    int right = 2*node+1;
    int mid = l+(r-l)/2;
    ll a = buildSegmentTree(arr,l,mid,left);
    ll b = buildSegmentTree(arr,mid+1,r,right);
    tree[node] = a|b;
    return tree[node];
}
    
ll query(int l,int r,int node,int left,int right)
{
    if(right < l || left > r)
    {
        return 0;
    }
    if(left == right){
        cout<<node<<" "<<tree[node]<<endl; 
        return tree[node];
    }
    if(left >= l&&right <= r){
        cout<<tree[node]<<"PPP"<<endl;
        return tree[node];
    }
    int mid = left + (right-left)/2;
    ll a=0,b=0;
    cout<<mid<<"mid"<<left<<"  "<<right<<endl;
    if(left<=l && l <= mid)
        ll a = query(l,r,2*node,left,mid);
    if(right >= r && mid <= r) 
        ll b = query(l,r,2*node+1,mid+1,right);
    
    cout<<"A"<<a<<"B"<<b<<endl;
    return a|b;

}


int main()
{
    ll arr[MAX+5],T,N;
    cin>>T>>N;
    for(int i=1;i<=T;i++)
    {
        cin>>arr[i];
    }
    buildSegmentTree(arr,1,T,1);
   cout<<query(1,4,1,1,5);






    return 0;
}