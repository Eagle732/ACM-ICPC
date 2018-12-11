#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MAXX 100005
lli arrA[MAXX],arrB[MAXX],sumA,sumB,diff_count;
int main()
{
	int N,T,flag=0;
	cin>>T;
	while(T--)
	{
		cin>>N;
		sumA=0,sumB=0,flag=1;
		for (int i = 1; i <= N; ++i)
		{
			cin>>arrA[i];
			sumA += arrA[i];
		}
		for (int i = 1; i <= N; ++i)
		{
			cin>>arrB[i];
			sumB += arrB[i];
		}
		if((sumB - sumA) % 6 != 0)
		{
			cout<<"NIE"<<endl;
			flag = 0;
			continue;
		}else{
			for(int i=N;i>2;i--)
			{
				if((arrB[i]-arrA[i])%3 != 0)
				{
					// cout<<"NIE"<<endl;
					flag = 0;
					break;
				}else{
					diff_count = (arrB[i]-arrA[i])/3;
					arrA[i-1] += 2*diff_count;
					arrA[i-2] += diff_count;
				}
			}
			if(arrA[1] == arrB[1] && arrA[2] == arrB[2] && flag == 1)
			{
				cout<<"TAK"<<endl;
			}else
			{
				cout<<"NIE"<<endl;
			}
		}
	}




	return 0;
}