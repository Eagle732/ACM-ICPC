#include<bits/stdc++.h>
using namespace std;
#define MAXX 100
int isPrime[MAXX];
bool arr[MAXX+5];
void seive()
{
	memset(arr,true,MAXX);
	for(int i=2;i<MAXX;i+=2)
	{
		
		arr[i] = false;
	}
	for(int i=3;i*i<=MAXX;)
	{
		for(int j = i*i;j<MAXX;j+=2*i)
		{
			if(arr[j] == true) 
			{
				arr[j] = false;
			}
		}
		cout<<i<<" ";
		while(arr[i])
		{
			cout<<"h";
			i+=2;
		}
	}
	for(int i=0;i<MAXX;i++)
	{
		if(arr[i])
			cout<<i<<" ";
	}
}
int main()
{
	seive();




	return 0;
}