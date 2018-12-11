#include<bits/stdc++.h>
using namespace std;
std::vector<int> prime,vec;
bool isPrime[100];
set<int>num;
map<int,vector<int> >cont;
void primeGenerator(){
	
	int count;
	isPrime[0] = isPrime[1] = false;
	isPrime[2] = true;
	for(int i=2;i<=50;i++)
	{
		count=0;
		for(int j=2;j<i;j++)
		{
			if(i%j==0)
			{
				count++;
			}
			if(count==0)
				isPrime[i] = true;
			else
				isPrime[i] = false;
		}
	}
	for(int i=2;i<=50;i++)
		if(isPrime[i]==true){
			prime.push_back(i);
		}}
int compress(int a){
	int num=1;
	for(int i=0;prime[i]<=a && i< prime.size();i++)
	{
		
		if(a%prime[i] == 0)
			num *= prime[i];
	}
	return num;
}
int gcd(int a,int b){
	if(b==0)
		return a;
	else
		return gcd(b,a%b);}
int main()
{
	int T,flag,N,out,counter,arr[100],primeCount=0,com;
	primeGenerator();
	cin>>T;
	while(T--){
		num.clear();
		cont.clear();
		vec.clear();
		primeCount = 0;
		
		cin>>N;
		for(int j=0;j<N;j++){
			cin>>arr[j];
			com = compress(arr[j]);
			num.insert(com);
			cont[com].push_back(j);
		}
		primeCount=0;
		for(set<int>::iterator itr = num.begin(); itr != num.end(); itr++){
			if(isPrime[*itr])
				primeCount++;
			vec.push_back(*itr);
			// cout<<*itr<<" ";
		}
		// cout<<"Prime count "<<primeCount<<endl;;
		if(primeCount > 3 || N==1 ){
			cout<<0<<endl;
			for(int j=0;j<N;j++)
			{
				cout<<arr[j]<<" ";
			}
			cout<<endl;
		}
		else
		{
			out=0;counter=0;
			for(int i=0;i<vec.size();i++)
			{
				counter=0;
				for(int j=0;j<vec.size();j++) if((i != j) && (gcd(vec[i],vec[j]) != 1))
				{
					counter++;
				}
				// cout<<vec[i]<<" counter "<<counter<<endl;
				
				if(counter == vec.size()-1)
				{
					for(int j=prime.size()-1;j>=0;j--)
					{
						flag = 0;
						for(int k=0;k<vec.size();k++) if(prime[j] == vec[k]) flag = 1;
						
						if(flag == 0)
						{
							arr[cont[vec[i]][0]] = prime[j];
							cout<<1<<endl;
							for(int i=0;i<N;i++)
							{
								cout<<arr[i]<<" ";
							}
							cout<<endl;
							out=1;
							break;
						}
					}
				}
				if(out==1) break;
			}	
			if(out == 0){
				cout<<0<<endl;
				for(int j=0;j<N;j++)
				{
					cout<<arr[j]<<" ";
				}
				cout<<endl;
			}
		}
	}
	return 0;
}