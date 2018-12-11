#include<bits/stdc++.h>
#define ll long long int
#define MAX 100005
#define MAXP 1000000007
using namespace std;
bool isHalf(string arr,int n)
{
    for(int i=0;i<n/2;i++)
    {
        if(arr[i] != arr[i+(n/2)])
            return false;
    }
    return true;
}

int moves(string arr,int n)
{
    int count = 0;
    if(n==0)
    return 0;
    if(n%2 == 0)
    {
        if(isHalf(arr,n))
        {
            count +=1 + moves(arr,n/2);
        }else
        {
            count += 2+ moves(arr,n-2);
        }
    }else
    {
        count += 1+moves(arr,n-1);
    }
    return count;
}
int main()
 {
     int T;
     cin>>T;
     string str;
     cin.ignore();
     while(T--)
     {
         getline(cin,str);
         cout<<moves(str,str.length());
     }
     return 0;
}