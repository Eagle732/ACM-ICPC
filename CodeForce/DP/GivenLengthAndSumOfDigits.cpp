#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
int main(){
	int minNum[MAX],maxNum[MAX],M,N;
	cin>>N>>M;
	if(N == 1 && M == 0){
		cout<<0<<" "<<0<<endl;
		return 0;
	}
	for(int i=0;i<N;i++){
		minNum[i] = 0;
		maxNum[i] = 9;
		if(i == 0)
			minNum[i] = 1;
	}
	int ansMin = 0,ansMAX = 0;
	if(M<1 || M>9*N){
		ansMin = -1;
		ansMAX = -1;
	}
	int maxVal = 9*N;
	int minVal = 1;
	int Mmin = M - minVal;
	int Mmax = maxVal - M;
	// cout<<Mmin<<"  "<<Mmax<<endl;
	if(ansMin != -1){
		for(int i=N-1;i>=0;i--)
		{
			if(Mmin > 9){

				minNum[i] += 9;
				Mmin -= 9;
				// cout<<"Min "<<i<<" "<<minNum[i]<<endl;
			}else{
				minNum[i] += Mmin;
				// cout<<"Min "<<i<<" "<<minNum[i]<<endl;
				break;
			}
		}
	}
	if(ansMAX != -1){
		for(int i=N-1;i>=0;i--)
		{	
			if(Mmax > 9){
				maxNum[i] -= 9;
				Mmax -= 9;
				// cout<<"Min "<<i<<" "<<maxNum[i]<<endl;
			}else{
				maxNum[i] -= Mmax;
				// cout<<"Min "<<i<<" "<<maxNum[i]<<endl;
				break;
			}		
		}
	}

	if(ansMin != -1){
		for(int i=0;i<N;i++)
			cout<<minNum[i];
	}else
	{
		cout<<-1;
	}
	cout<<" ";
	if(ansMAX != -1){
		for(int i=0;i<N;i++)
			cout<<maxNum[i];
	}else
	{
		cout<<-1;
	}
// 	int s = M;
// 	int m = N;
// 	string minn="";
//  	int sum = s;
//     for (int i = 0; i < m; i++)
//         for (int d = 0; d < 10; d++)
//             if ((i > 0 || d > 0 || (m == 1 && d == 0)) && can(m - i - 1, sum - d))
//             {
//                 minn += char('0' + d);
//                 sum -= d;
//                 break;
//             }
// cout<<endl<<minn<<endl;
	return 0;
}