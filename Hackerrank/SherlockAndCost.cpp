#include<bits/stdc++.h>
using namespace std;
#define MAXX 100005
void cp(int index,int a,int b,int dp[][])
{
    for(int i=index;i>=a;i--)
    {
        dp[i][1-b] = dp[i][b];
    }
}
int main()
{
    int T,N,arr[MAXX],dp[MAXX][3];
    cin>>T;
    while(T--)
    {
        cin>>N;
        for(int i=0;i<N;i++)
        {
            cin>>arr[i];
        }
        dp[0][0] = 1;
        dp[0][1] = arr[0];
        cost[0][0] = 1;cost[0][1] = arr[0];
        for(int i=1;i<N;i++)
        {
            if(abs(dp[i-1][0]-arr[i]) > abs(dp[i-1][1]-1))
            {
                dp[i][0] = arr[i];    
            }
            else
            {
                dp[i][0] = 1;
            }

            if(abs(dp[i-1][0]-arr[i]) > abs(dp[i-1][1]-1))
            {
                dp[i][1] =  arr[i];  
            }
            else
            {
                dp[i][1] = 1;
            }
            cost[i][0] += max(dp[i-1][0] -dp[i][0]);
            cost[i][1] += max(dp[i-1][1] -dp[i][1]);
            if(dp[i][1] == dp[i][0])
            {
                if(cost[i][0] > cost[i][1])
                {
                    cp(index,i,0,dp);
                }else
                {
                    cp(index,i,1,dp);
                }
                index = i;

            }
        }
    }






    return 0;
}