#include<iostream>
using namespace std;
#define MAX 100005
long long int A[MAX],B[MAX],N,Q,l,r,C,sum;
int main(){
    cin>>N>>Q;
    A[0] = 0;
    B[0] = 0;
    for(int i=1;i<=N;i++){
        cin>>C;
        if(i > 2)
            A[i] = A[i-2] + C;
        else
            A[i] = C;
    }
    for(int i=1;i<=N;i++){
        cin>>C;
        if(i > 2)
            B[i] = B[i-2] + C;
        else
        B[i] = C;
    }
    while(Q--){
        cin>>C>>l>>r;
       if(C==1)
       {
           if(l>2){
                if((r-l)%2 == 0)
                {
                    sum = A[r] - A[l-2] + B[r-1] - B[l-1];
                }else
                {
                    sum = A[r-1] - A[l-2] + B[r] - B[l-1];
                }
            }else{
                if((r-l)%2 == 0)
                {
                    sum = A[r]  + B[r-1];
                }else
                {
                    sum = A[r-1]  + B[r];
                }
            }           
       }else{
           if(l>2){
                if((r-l)%2 == 0)
                {
                    sum = B[r] - B[l-2] + A[r-1] - A[l-1];
                }else
                {
                    sum = B[r-1] - B[l-2] + A[r] - A[l-1];
                }
            }else{
                if((r-l)%2 == 0)
                {
                    sum = B[r]  + A[r-1];
                }else
                {
                    sum = B[r-1]  + A[r];
                }
       		}
       	}	
       cout<<sum<<endl;
       sum = 0;
    }
    
    return 0;
    
}