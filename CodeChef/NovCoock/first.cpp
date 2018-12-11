#include<bits/stdc++.h>
using namespace std;
#define lli long long int
set<lli>cont1,cont2;
int main()
{
	lli T,A,B,flag;
	cin>>T;
	for(int i=0;i<T;i++)
	{
			cin>>A;
			flag = 0;
			for(int k=0;k<A;k++)
			{
				cin>>B;
				cont1.insert(B);
			}
			lli size1 = cont1.size();
			cin>>A;
			for(int k=0;k<A;k++)
			{
				cin>>B;
				cont2.insert(B);
			}
			lli size2 = cont2.size();
			cin>>A;
			for(int k=0;k<A;k++)
			{
				cin>>B;
				cont1.insert(B);
				if(cont1.size() != size1){
					flag = 1;
				}
			}
			cin>>A;
			for(int k=0;k<A;k++)
			{
				cin>>B;
				cont2.insert(B);
				if(cont2.size() != size2){
					flag = 1;
				}
			}
		
		if(flag == 1)
			{
				cout<<"no"<<endl;
			}else
			{
				cout<<"yes"<<endl;
			}
			cont1.clear();
			cont2.clear();
	}
}