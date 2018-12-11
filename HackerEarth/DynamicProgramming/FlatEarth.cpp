#include<bits/stdc++.h>
using namespace std;
long table[300][200];
long getWays(long n, long arr[],int a) {
    if(a < 0)
        return 0;
    if(n == 0)
        return 1;
    if(n<0)
    	return 0;
    if(table[n][a] != -1)
        return  table[n][a];
    table[n][a] = getWays(n-arr[a],arr,a)+getWays(n,arr,a-1);
    return table[n][a];
    // return sum;
}

int main()
{
    memset(table,-1,sizeof table);
    int T,N;
    long arr[500];
    // vector<long>vec;
    cin>>T>>N;
    for(int i=0;i<N;i++)
    {
    	cin>>arr[i];
    }
    // sort(vec.begin(),vec.end());
    cout<<getWays(T,arr,N-1);





    return 0;
}