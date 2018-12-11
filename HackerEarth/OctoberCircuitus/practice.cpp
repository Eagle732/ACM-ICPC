#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a=2,b=-7,p=10;
	for(int i=p;i>=0;i--)
	{
		for(int j=0;j<=p-i;j++)
		{
			cout<<(b*i)+(a*j)<<setw(8);
		}
		cout<<endl;
	}




	return 0;
}