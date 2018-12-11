#include<bits/stdc++.h>
using namespace std;
#define lli long long int
lli N,K,T,A,B,rem,count_r;
lli Comb(lli a,lli b)
{
  a--,b--;
  rem = a-b;
  if(rem > b)
  {
    rem = b;
  }
  b = rem;
  count_r = 1;
  while(rem)
  {
    count_r *= (a-rem+1);

    count_r /= (b-rem+1);
    // cout<<a-rem<<"  "<<b-rem+1<<endl;
    rem--;
  }
  return count_r;
}
int main()
{
  cin>>T;
  while(T--)
  {
    cin>>A>>B;
    cout<<Comb(A,B)<<endl;
  }




  return 0;
}
