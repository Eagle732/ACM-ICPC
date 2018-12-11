#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MAXX 100005
vector<pair<int,lli> >vec;
lli T,N,arr[MAXX],diff,K,K1,flag,count_minus;
int main()
{
	cin>>T;
	while(T--)
	{
		vec.clear();
		cin>>N;
		K=-1;
		K1=-1;
		flag=0;
		count_minus = 0;

		for(int i=0;i<N;i++)
		{
			cin>>arr[i];
			if(arr[i] == -1)
				count_minus++;
			if(arr[i] != -1)
			{
				vec.push_back(make_pair(i,arr[i]));
			}
		}
		if(count_minus > N-2)
		{
			cout<<"inf"<<endl;
			flag=1;
			continue;
		}
		for(int i=0;i<vec.size()-1;i++)
		{
			pair<int,lli> A = vec[i];
			pair<int,lli> B = vec[i+1];
			if(A.second >= B.second)
			{
				// cout<<"Hello";
				diff = (B.first - A.first - B.second);
				if(diff >= 0){
					K1 = A.second + diff;
					if(K ==-1)
					{
						// cout<<"Hello2";
						K = K1;
					}else
					{
						if(K != K1){
							cout<<"impossible"<<endl;
							flag =1;
							break;
						}
					}
				}
				else
				{
					cout<<"impossible"<<endl;
							flag =1;
							break;
				}
			}else{
			
				diff = (B.first-A.first);
				if(A.second + diff != B.second||(K != -1 && K < diff+A.second))
				{
					cout<<"impossible"<<endl;
					flag = 1;
					break;
				}
				
		
			}
		}
		if(flag == 0)
		{
			if(K != -1)
				cout<<K<<endl;
			else
				cout<<"inf"<<endl;
		}
	}
	return 0;
}
