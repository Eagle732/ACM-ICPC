#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    queue<int>q,prevQ;
    string str[1005];
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>str[i];
        q.push(i);
    }
    int j = 0;
    int p = q.size();
    while(j<M && q.size() > 0)
    {
        int k = q.front();
        q.pop();
        if(str[k][j] == '1'){
            prevQ.push(k);
            q.push(k);
        }
        else{
            prevQ.push(k);
        }

        p--;
        // cout<<p<<" ";

        if(p == 0)
        {
            p = q.size();
            j++;
            if(p == 0){
                while(!prevQ.empty())
                {
                    q.push(prevQ.front());
                    prevQ.pop();
                }
                p = q.size();
            }else if(p == 1){
                break;
            }
            while(!prevQ.empty())
            prevQ.pop();
        }
       // if(p ==0){
       //      cout<<endl;
       //      cout<<q.size()<<"  "<<prevQ.size()<<endl;
       //      while(!q.empty()){
       //          cout<<q.front()<<endl;
       //          q.pop();
       //      }

       //      cout<<q.size()<<" ff "<<prevQ.size()<<endl;
       //      while(!prevQ.empty()){
       //          cout<<!prevQ.front()<<endl;
       //          prevQ.pop();
       //      }
       //      break;
       //  }
    }
    
    if(q.size()>0)
        cout<<q.front();

    return 0;
}