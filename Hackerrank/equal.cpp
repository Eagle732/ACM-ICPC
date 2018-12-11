#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define lli long long int
vector<int>vec;
lli sum=0;
int main()
{
    int T,N,A,num,minn;
    cin>>T;
    while(T--)
    {
        cin>>N;
        sum=0;
        minn=99999;
        
        for(int i=0;i<N;i++)
        {
            cin>>A;
            vec.push_back(A);
            // cout<<sizeof(vec)<<endl;
            if(minn > A)
                minn = A;
        }
        // cout<<sizeof(vec)<<endl;
        for(int i=0;i<N;i++)
        {
            num = vec[i]-minn;
            // cout<<"SUm :"<<sum<<"  "<<num<<endl;
            sum += (num)/5;
            num %= 5;
            sum += num/2;
            num %= 2;
            sum += num;

        }
        vec.clear();
        cout<<sum<<endl;
    }
    
    
    
    return 0;
}