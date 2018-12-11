#include<bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define ull unsigned ll

void unionInit(int d[],int s){
  int i;
  rep(i,s) d[i]=i;
}

int unionGet(int d[],int n){
  int t=n, k;
  while(d[t] != t) t=d[t];
  while(d[n] != n) k=d[n], d[n]=t, n=k;
  return n;
}

int unionConnect(int d[],int a,int b){
  a = unionGet(d, a);
  b = unionGet(d, b);
  if(a==b) return 0;
  d[a]=b;
  return 1;
}
 
int T;
int N, M, Q, NM;
int mp1[1000][1000], mp2[1000][1000];
int sz[1000000], ind[1000000], mx;
int TYPE[1000000], X1[1000000], Y1[1000000], X2[1000000], Y2[1000000];
 
int main(){
  int i, j, k;
  ll res;

  scanf("%d",&T);
  while(T--){
    scanf("%d%d%d",&N,&M,&Q);
    NM = N*M;
 
    res = 0;
    rep(i,N) rep(j,M) mp1[i][j] = mp2[i][j] = 0;
    
    rep(i,Q){
      scanf("%d",TYPE+i);
      if(TYPE[i]==1){
        scanf("%d%d",X1+i,Y1+i);
        X1[i]--; Y1[i]--;
        mp1[X1[i]][Y1[i]]++;
      }
      if(TYPE[i]==2){
        scanf("%d%d",X1+i,Y1+i);
        X1[i]--; Y1[i]--;
        mp2[X1[i]][Y1[i]]++;
      }
      if(TYPE[i]==3){
        scanf("%d%d%d%d",X1+i,Y1+i,X2+i,Y2+i);
        X1[i]--; Y1[i]--; X2[i]--; Y2[i]--;
      }
    }
    
    unionInit(ind, NM);
    rep(i,NM) sz[i] = 0; mx = 0;
    rep(i,N) rep(j,M-1) if(!mp1[i][j]) unionConnect(ind, i*M+j, i*M+j+1);
    rep(i,N-1) rep(j,M) if(!mp2[i][j]) unionConnect(ind, i*M+j, i*M+j+M);
    
    rep(i,NM){
      k = unionGet(ind,i);
      sz[k]++;
      mx = max(mx, sz[k]);
    }
    
    for(i=Q-1;i>=0;i--){
      if(TYPE[i]==1){
        if(--mp1[X1[i]][Y1[i]]==0){
          j = unionGet(ind, X1[i]*M+Y1[i]);
          k = unionGet(ind, X1[i]*M+Y1[i]+1);
          if(unionConnect(ind, j, k)){
            sz[k] += sz[j];
            mx = max(mx, sz[k]);
          }
        }
      }
      if(TYPE[i]==2){
        if(--mp2[X1[i]][Y1[i]]==0){
          j = unionGet(ind, X1[i]*M+Y1[i]);
          k = unionGet(ind, X1[i]*M+Y1[i]+M);
          if(unionConnect(ind, j, k)){
            sz[k] += sz[j];
            mx = max(mx, sz[k]);
          }
        }
      }
      if(TYPE[i]==3){
        if(unionGet(ind,X1[i]*M+Y1[i])==unionGet(ind,X2[i]*M+Y2[i])) res++;
      }
      if(TYPE[i]==4){
        res += mx;
      }
    }

    printf("%lld\n", res);
  }
  return 0;
}