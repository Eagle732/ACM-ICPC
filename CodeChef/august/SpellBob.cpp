#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	string str1,str2;
	cin>>T;
	cin.ignore();
	for(int i=0;i<T;i++)
	{
		getline(cin,str1);
		getline(cin,str2);
		int B_bob=0,O_bob=0,C_bob=0;
		for(int i=0;i<3;i++)
		{
			if(str1[i] == 'o' || str2[i] == 'o'){
				O_bob++;
			}
			if(str1[i] == 'b' || str2[i] == 'b')
			{
				B_bob++;
			}
			if(str1[i] == 'o' || str2[i] == 'o'||str1[i] == 'b' || str2[i] == 'b')
			{
				C_bob++;
			}
		}
		// cout<<C_bob<<" "<<B_bob<<" "<<O_bob<<endl;
		if(C_bob == 3 && B_bob > 1 && O_bob >0){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}



	}
	return 0;
}