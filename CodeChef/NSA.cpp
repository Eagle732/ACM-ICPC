#include<bits/stdc++.h>
using namespace std;
int main(){
	map<char,int>container;
	int arr[30],count_t=0;
	for(int i=0;i<30;i++){
		arr[i] = 0;
	}
	int T;
	cin>>T;
	cin.ignore();
	string Str;
	for(int i=0;i<T;i++){
		getline(cin,Str);
		for(int j=0;j<Str.length();j++){
			arr[(int)(Str[j] - 'a')]++;
			if(container.count(Str[j])==0)
			{
				container[Str[j]] = 0;
			}
			for(map<char,int>::reverse_iterator itr( container.find(Str[j]));itr != container.rend();itr++)
			{
				itr->second += arr[itr->first - 'a'];
			}

		}
		for(map<char,int>::iterator itr = container.begin();itr != container.end();itr++)
		{
			cout<<itr->first<<"  "<<itr->second<<endl;
			count_t +=itr->second;
		}
		cout<<count_t<<endl;
		container.clear();
		count_t=0;
	}



	return 0;
}