#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
	lli T,R,G,Rcount,Gcount;
	string str;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		R=G=0;
		Rcount = Gcount = 0;
		cin>>str;
		if(str.length()%2 != 0)
		{
			cout<<"no"<<endl;
			continue;
		}else
		{
			for(int i=0;i<str.length()-1;i++)
			{
				if(str[i] == 'R'&&str[i+1] == 'R')
					R++;
				
				if(str[i] == 'G' && str[i+1] == 'G')
					G++;
				if(str[i] == 'R')
					Rcount++;
				if(str[i] == 'G')
					Gcount++;
			}
			if(str[0] == 'R'&&str[str.length()-1] == 'R')
					R++;
			if(str[0] == 'G' && str[str.length()-1] == 'G')
					G++;

			if(str[str.length()-1] == 'R')
				Rcount++;
			if(str[str.length()-1] == 'G')
				Gcount++;
			if(((R == 1 && G == 1 )||(R == 0 && G == 0 ))&&(Rcount == Gcount))
				cout<<"yes"<<endl;
			else
				cout<<"no"<<endl;
		}

	}



	return 0;
}