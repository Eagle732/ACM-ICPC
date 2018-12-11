
#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int main() {
    // your code goes here
    #ifdef JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));
    int n;
    cin>>n;
    int p1[n],p2[n];
    for(int i=0;i<n;i++)
        p1[i]=p2[i]=i+1;//Initialize permutations.
    for(int i=1;i<n;i++)//Set p2
        p2[i]=i;
    p2[0]=n;//p2 Done.
    for(int i=0;i<n;i++)//Now find p1
    {
        if(i<n/2-(n%2==0))
            p1[i]=i+2;
        else if(i==n/2-(n%2==0))
            p1[i]=1;
        else if(i!=n-1)
            p1[i]=i+2;
        else 
            p1[i]=n/2+2-(n%2==0);//You can come up with your own custom implementation
            //to find p1. 
    }
    for(int i=0;i<n;i++)
        cout<<p1[i]<<" ";cout<<endl;
    for(int i=0;i<n;i++)
        cout<<p2[i]<<" ";cout<<endl;
    return 0;
}