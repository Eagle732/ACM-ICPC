#include<bits/stdc++.h>
using namespace std;
#define lli long long int
set<lli>cont;
int main()
{
    lli A,N;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>N;
        for(int i=0;i<N;i++)
        {
            cin>>A;
            if(A<=N)
            {
                cont.insert(A);
            }
        }
        cout<<N-cont.size()<<endl;
        cont.clear();
    }
    return 0;
}
