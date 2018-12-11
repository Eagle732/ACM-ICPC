#include<bits/stdc++.h>
using namespace std;
#define lli long long 
lli table[40][40][40][2],j;
lli A,B,C,maxx;
lli dynamic_ways(lli A,lli B,lli C,int index,int Aleft,int Bleft,int borrow,string strA,string strB)
{
	if(index > maxx || (Aleft <= 0 && Bleft <= 0 && borrow == 0 && index!= maxx-1)||Aleft<0||Bleft<0){
		// cout<<"Hello4";
		return 0;
	}
	if(index==maxx-1 && (Aleft + Bleft + borrow) > 1)
	{
		// cout<<"Hello3";
		return 0;
	}
	if(index == maxx-1)
	{
		if((C & (1<<index) == 0))
		{
			if(Aleft + Bleft + borrow == 0){
				// cout<<'0'+strA<<endl<<'0'+strB<<endl<<endl<<endl;
				return 1;
			}
			else
			{
				// cout<<"Hello1";
				return 0;
			}
		}else
		{
			if(Aleft+Bleft+borrow == 1)
			{
				// if(Aleft==1)
				// 	cout<<'1'+strA<<endl<<'0'+strB<<endl<<endl<<endl;
				// if(Bleft==1)
				// 	cout<<'0'+strA<<endl<<'1'+strB<<endl<<endl<<endl;
				// if(borrow==1){

				// 	cout<<'0'+strA<<endl<<'0'+strB<<endl<<endl<<endl;
				// }
				return 1;
			}
			else{
				// cout<<"Hello";
				return 0;
			}
		}
	}
	if(table[index][Aleft][Bleft][borrow] != -1)
	{
		return table[index][Aleft][Bleft][borrow];
	}

	if((C&(1<<index)) == 0)
	{
		if(borrow == 0)
		{
			// cout<<"1"<<endl;
			table[index][Aleft][Bleft][borrow] = dynamic_ways(A,B,C,1+index,Aleft,Bleft,0,'0'+strA,'0'+strB)+
				dynamic_ways(A,B,C,1+index,Aleft-1,Bleft-1,1,'1'+strA,'1'+strB);
		}else
		{
			// cout<<"2"<<endl;
			table[index][Aleft][Bleft][borrow] = dynamic_ways(A,B,C,1+index,Aleft,Bleft-1,1,'0'+strA,'1'+strB)+
				dynamic_ways(A,B,C,1+index,Aleft-1,Bleft,1,'1'+strA,'0'+strB);
		}
		
	}else
	{
		if(borrow == 1)
		{
			// cout<<"3"<<endl;
			table[index][Aleft][Bleft][borrow] = dynamic_ways(A,B,C,1+index,Aleft,Bleft,0,'0'+strA,'0'+strB)+
				dynamic_ways(A,B,C,1+index,Aleft-1,Bleft-1,1,'1'+strA,'1'+strB);
		}else
		{
			// cout<<"4"<<endl;
			table[index][Aleft][Bleft][borrow] = dynamic_ways(A,B,C,1+index,Aleft,Bleft-1,0,'0'+strA,'1'+strB)+
				dynamic_ways(A,B,C,1+index,Aleft-1,Bleft,0,'1'+strA,'0'+strB);
		}
	}
	return table[index][Aleft][Bleft][borrow];
}



int main()
{
	int T,Aleft,Bleft;
	cin>>T;
	
	for (int i = 0; i < T; ++i)
	{
		memset(table,-1,sizeof table);
		Aleft = 0;
		Bleft = 0;
		maxx=0;
		cin>>A>>B>>C;
		for(j=1;j<=C;j = j<<1)
		{
			maxx++;
			if((A&j)!=0)
			{
				Aleft++;
			}
			if((B&j)!=0)
			{
				Bleft++;
			}
		}
		cout<<dynamic_ways(A,B,C,0,Aleft,Bleft,0,"","")<<endl;
	}
	return 0;
}