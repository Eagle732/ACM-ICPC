#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define lli long long int
set<int>cont;
lli sum=0;
int main()
{
    int T,N,A,num;
    cin>>T;
    while(T--)
    {
        cin>>N;
        sum=0;
        
        for(int i=0;i<N;i++)
        {
            cin>>A;
            cont.insert(A);
        }
        set<int>::iterator itr1 = cont.begin();
        itr1++;
        for(set<int>::iterator itr = cont.begin(); itr1 != cont.end();itr++,itr1++)
        {
            num = *(itr1)-*(itr);
            sum += (num)/5;
            num %= 5;
            sum += num/2;
            sum %= 2;
            sum += num;
        }
        cout<<sum<<endl;
    }
    
    
    
    return 0;
}