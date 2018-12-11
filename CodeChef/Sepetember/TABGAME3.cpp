#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,A,B,Q;
	cin>>T;
	cin.ignore();
	string str1,str2,res[100005];
	// vector<bool>vec[100005];
	for(int i=0;i<100000;i++)
		res[i] = "a";
	while(T--)
	{
		getline(cin,str1);
		getline(cin,str2);
		long long int len1 = str1.length();
		long long int len2 = str2.length();
		int a=0,b=0;
		char c;
		c = str2[0];
		for(long long int i=1;i<=(len1*len2);i++)
		{
			if(str1[a] == '0' || c == '0'){
				str1[a] = '1';
				c = '1';
				// cout<<"1";
				res[1+((i-1)/len1)] += "1";
			}else
			{
				str1[a]='0';
				c = '0';
				// cout<<"0";
				res[1+((i-1)/len1)] += "0";
			}
			a++;
			if(a >= len1){
				a = 0;
				c = str2[(i)/len1];
				// cout<<endl;
			}
		}
		for(int A=1;A<str1.length();A++)
		{
			for(B=1;B<str2.length();B++)
			{
			// cin>>A>>B;
			printf("%c",res[A][B]);
		}
		cout<<endl;
	}
	}




	return 0;

}