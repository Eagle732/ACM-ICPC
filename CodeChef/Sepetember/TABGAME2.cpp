//teja349
#include <bits/stdc++.h>
 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
vector<vii> vec(123456);
char ans[123456];
int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        string c;
        string r;
        cin>>r>>c;
        int i,j;
        int n=c.length();
        int m=r.length();
        rep(i,n+10){
            vec[i].clear();
        }
        int q,pos;
        cin>>q;
        int a,b;//note down queries.
        rep(i,q){
            cin>>a>>b;
            vec[a].pb(mp(b,i));
        }
        string s="";
        fd(i,r.length()-1,0)
            s+=r[i];
        r=s;
        int len=r.length();
        r+='0';
        f(i,1,n+1){
            // simulating the problem statement for first 10 rows. Becuase there is no good pattern in first three rows
            if(i<10){
                r[len]=c[i-1];
                fd(j,len-1,0){
                    if(r[j+1]=='1' && r[j]=='1')
                        r[j]='0';
                    else
                        r[j]='1';
                }
            }
            else{
                // correspondingly updating pattern for each row from previous row based on the element.
                if(r[len-1]=='0'){
                    r[len]='1';

                }
                else{
                    if(c[i-1]=='1'){
                        r[len]='0';
                    }
                    else{
                        r[len]='1';
                        if(len-2>=0 && r[len-2]=='1')
                            r[len-1]='0';
                    }
                }
                len++;
                r+='0';
            }

            // answering queries in that row.
            rep(j,vec[i].size()){
                pos=vec[i][j].ss;
                b=vec[i][j].ff;
            	cout<<len<<"  "<<b<<endl;
                ans[pos]=r[len-b];
            }

        }
        rep(i,q){
            cout<<ans[i];
        }
        cout<<endl;

    }
    return 0;   
}