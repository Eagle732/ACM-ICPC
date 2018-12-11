#include<bits/stdc++.h>
using namespace std;
string str1,str2;
void constructString(string str,string &res,char c)
{
	for(int i=0;i<str.length();i++)
	{
		if(str[i] == '0' || c == '0')
		{
			res += '1';
			c = '1';
		}else
		{
			res += '0';
			c = '0';
		}
	}
}
int main()
{
	int T,A,B,Q;
	cin>>T;	
	while(T--)
	{
		cin.ignore();
		string str,str2,str_5,str_6;
		getline(cin,str);
		getline(cin,str2);

		long long int len1 = str.length();
		long long int len2 = str2.length();
		
		string str_1,str_2,str_3,str_4;
		constructString(str,str_1,str2[0]);
		constructString(str_1,str_2,str2[1]);
		constructString(str_2,str_3,str2[2]);
		
		constructString(str2,str_4,str[0]);
		constructString(str_4,str_5,str[1]);
		constructString(str_5,str_6,str[2]);

		
		cin>>Q;
		while(Q--){
			cin>>A>>B;
			A--;B--;
			int a = min(A,B)-2;
			
			if(A>=2 && B>=2)
			{
				if(B>=A)
					printf("%c",str_3[B-a]);
				else if(A>B)
					printf("%c",str_6[A-a]);
			}else if(A == 0)
			{
				printf("%c",str_1[B]);
			}else if(B == 0)
			{
				printf("%c",str_4[A]);
			}else if(A == 1)
			{
				printf("%c",str_2[B]);
			}else if(B == 1)
			{
				printf("%c",str_5[A]);
			}


			// }
			
		}
		cout<<endl;
	}
	return 0;

}
