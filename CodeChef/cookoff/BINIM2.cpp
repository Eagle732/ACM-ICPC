#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str,str1;
	int T,N,arr[5];
	cin>>T;
	while(T--)
	{
		memset(arr,0,sizeof arr);
		cin>>N>>str;
		for(int i=0;i<N;i++)
		{
			cin>>str1;
			if(str1[0] == '0' && str1[str1.length()-1] == '0')
			{
				arr[0]++;
			}else if(str1[0] == '0' && str1[str1.length()-1] == '1')
			{
				arr[1]++;
			}else if(str1[0] == '1' && str1[str1.length()-1] == '0')
			{
				arr[2]++;
			}else if(str1[0] == '1' && str1[str1.length()-1] == '1')
			{
				arr[3]++;
			}
		}
		if(str == "Dee")
		{
			if(arr[0]<=arr[3])
			{
				cout<<"Dee"<<endl;
			}else
			{
				cout<<"Dum"<<endl;
			}
		}else
		{
			if(arr[3]<= arr[0])
			{
				cout<<"Dum"<<endl;
			}else
			{
				cout<<"Dee"<<endl;
			}
		}
	}



	return 0;
}