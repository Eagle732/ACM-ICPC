#include<bits/stdc++.h>
using namespace std;
set<char>cont;
int main()
{
	int counter,maxLength,K;
	string str;
	getline(cin,str);
	cin>>K;
	maxLength = 0;
	for(int i=0;i<str.length();i++)
	{
		for(int j=i+K;j<str.length();j++)
		{
			counter = 1;
			if(str[i] == str[j])
			for(int k=0;k+i<j;k++)
			{
				if(str[i+k] == str[j+k])
				{
					counter++;
				}else
				{
					if(maxLength < counter)
					{
						maxLength = counter;
					}
					counter = 0;
				}
			}

		}
	}
	cout<<maxLength+2*K;
	return 0;
}