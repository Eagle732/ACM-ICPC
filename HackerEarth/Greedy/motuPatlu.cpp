#include<bits/stdc++.h>
using namespace std;
#define MAX 100000+7
long long int T,N,arr[MAX];
int main(){
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=1;i<=N;i++){
            cin>>arr[i];
        }
        int motu=1,patlu=N;
        int motu_count = 0,patlu_count=0;
        int motu_Cap = 0,patlu_Cap = 0;
        while((motu_count + patlu_count) <=N && motu <= patlu)
        {
            if(motu_Cap <= patlu_Cap){
                motu_Cap += arr[motu++];
                motu_count++;
            }
            if(motu_Cap >= patlu_Cap){
                patlu_Cap += 2*arr[patlu--];
                patlu_count++;
            }
            
        }
        cout<<motu_count<<" "<<patlu_count<<endl;
        
        if(motu_count > patlu_count){
            cout<<"Motu"<<endl;
        }
        else{
            cout<<"Patlu"<<endl;
        }
    }
}