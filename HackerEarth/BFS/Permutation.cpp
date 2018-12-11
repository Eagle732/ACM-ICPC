#include<bits/stdc++.h>
using namespace std;
map<string,int>cont;
queue<string>q;
int main()
{
	int n;
	cin>>n;
	char a;
	string str="",res="";
	for (int i = 1; i <= n; ++i)
	{
		cin>>a;
		str += a;
		res += i+'0';
	}
	// cout<<res<<endl;
	cont[str] = 0;
	q.push(str);
	while(!q.empty())
	{
		str = q.front();
		q.pop();
		if(str == res){

			cout<<cont[res];
			return 0;
		}
		for(int i=2;i<=n;i++){
			string nxt = str;
			reverse(nxt.begin(),nxt.begin()+i);
			// cout<<"rev : "<<i<<nxt<<endl;
			if(cont.find(nxt) == cont.end())
			{
				cont[nxt] = cont[str] + 1;
				q.push(nxt);
			}
		}
	}
	cout<<cont.size();

	return 0;
}