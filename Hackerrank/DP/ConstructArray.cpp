#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define maxx 100005
#define MOD 1000000007
lli table[maxx][2];
lli constructTable(int n,int index,int K)
{
    if(n == 3 && index == 0)
        return table[n][0];
    else if(n == 3 && index == 1)
        return table[n][1];
    else
    {
        lli P = constructTable(n-1,0,K);
        lli Q = constructTable(n-1,1,K);
        if(index == 0)
        {
            table[n][0] = (Q*(K-1))%MOD;
            return table[n][0];
        }else
        {
            table[n][1] = (P+(Q*(K-2)))%MOD;
            return table[n][1];
        }
    }
}
int main()
{
    int N,K,X;
    cin>>N>>K>>X;
    table[3][0] = K-1;
    table[3][1] = K-2;
    for(int i=4;i<=N;i++)
    {
        table[i][0] = (table[i-1][1]*(K-1))%MOD;
        table[i][1] = (table[i-1][0]+(table[i-1][1]*(K-2)))%MOD;
    }
    if(X == 1)
        cout<<table[N][0];
    else
        cout<<table[N][1];
    return 0;
}