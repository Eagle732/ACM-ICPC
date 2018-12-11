#include<bits/stdc++.h>
#define ll long long int
#define MAX 100005
#define MAXP 1000000007
using namespace std;
long long int table[85][80];
void func()
{
    table[1][0]=1;
    table[1][1]=1;
    for(int i=2;i<81;i++)
    {
        for(int j=0;j<i;j++)
        {
            table[i][j] = table[i-1][j-1] + table[i-1][j];
        }
        table[i][i]=1;
    }
}
long long int ANS(int a,int b)
{
    if(a == 0)
        return 1;
    else
    return ANS(a-1,b+4)+table[a][b];
}

int main()
{
    int T,A,a,b;
    cin>>T;
    func();
    while(T--)
    {
        cin>>A;
        int a = A/4;
        int b = A%4;
        cout<<ANS(a,b)<<endl;
    }
    
    
    
    
	return 0;
}