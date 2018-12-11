#include<bits/stdc++.h>
#define ll long long int
#define MAX 100005
#define MAXP 1000000007
using namespace std;
long long int table[1005][1005];
void funct()
{
    for(int i=1;i<1001;i++)
    {
        table[i][0]=1;
        for(int j=1;j<i;j++)
        {
            table[i][j] = table[i-1][j-1]+table[i-1][j];
            table[i][j] %= 1000000007;
            
        }
        table[i][i]=1;
    }
    return ;
}
int main()
 {
    long long int count_t=0,T,n;
    cin>>T;
    funct();
    while(T--)
    {
        count_t=0;
        cin>>n;   
        for(int i=0;i<=n;i++)
        {
            count_t += table[n][i]*table[n][i];
            count_t %= 1000000007;
        }
        cout<<count_t<<endl;
    }
    
    return 0;
}