#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int,int>pii;
typedef unsigned long long u64;
typedef unsigned int u32;
namespace io{

const int L=1<<21|1;
char ibuf[L],*iS,*iT,obuf[L],*oS=obuf,*oT=obuf+L-1,c,st[55];int tp;
#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,L,stdin),(iS==iT?EOF:*iS++)):*iS++)
void flush(){fwrite(obuf,1,oS-obuf,stdout);oS=obuf;}
void putc(char x){*oS++=x;if(oS==oT)flush();}

template<class I>void gi(I&x){
	for(c=gc();c<'0'||c>'9';c=gc());
	for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);
}template<class I>void print(I x){
	while(x)st[++tp]=x%10+'0',x/=10;
	while(tp)putc(st[tp--]);
}}using io::gi;

const int N=1005,M=1e6+5;
int n,m,K,a[N][N],P[N][N];
bool G[N][N],ff[N][N];
vector<pii>L;

void dfs(int ux,int uy,int vx,int vy){
	int x,y;
	if(vx-ux<=100){
		for(x=ux;x<=vx;x++)G[x][uy]=true;
		if(uy+2<=vy){
			G[vx][uy+1]=true;
			for(x=ux;x<=vx;x++)G[x][uy+2]=true;
			if(uy+4<=vy)G[ux][uy+3]=true,dfs(ux,uy+4,vx,vy);
		}
		return;
	}
	if(vy-uy<=100){
		for(y=uy;y<=vy;y++)G[ux][y]=true;
		if(ux+2<=vx){
			G[ux+1][vy]=true;
			for(y=uy;y<=vy;y++)G[ux+2][y]=true;
			if(ux+4<=vx)G[ux+3][uy]=true,dfs(ux+4,uy,vx,vy);
		}
		return;
	}
	for(y=uy;y<=vy;y++)G[ux][y]=true;
	for(x=ux;x<=vx;x++)G[x][vy]=true;
	for(y=ux;y<=vy;y++)G[vx][y]=true;
	for(x=ux+2;x<=vx;x++)G[x][uy]=true;
	G[ux+2][uy+1]=true;
	dfs(ux+2,uy+2,vx-2,vy-2);
}
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
void dfs(int x,int y){
	L.pb(pii(x,y)),G[x][y]=false;int e;
	for(e=0;e<4;e++)if(G[x+dx[e]][y+dy[e]])dfs(x+dx[e],y+dy[e]);
	G[x][y]=true;
}
bool chk(int x,int y){
	for(int e=0;e<4;e++)if(G[x+dx[e]][y+dy[e]]&&!ff[x+dx[e]][y+dy[e]])return false;
	return true;
}
namespace subsetsum{
	const int M=1.05e6;
	int n,m;
	u64 s1[M],s2[M],ts[M];
	u64 main(vector<u32>p,u64 s){
		int x,i,j,k;
		n=p.size();
		vector<u32>a(p.begin(),p.begin()+(n>>1));
		vector<u32>b(p.begin()+(n>>1),p.end());
		s1[0]=0;
		for(x=0,m=a.size();x<m;x++){
			u32 c=a[x];
			for(i=j=k=0;i<1<<x;i++){
				while(s1[j]+c<s1[i])ts[k++]=s1[j++]+c;
				ts[k++]=s1[i];
			}
			while(j<1<<x)ts[k++]=s1[j++]+c;
			memcpy(s1,ts,(2<<x)<<3);
		}
		s2[0]=0;
		for(x=0,m=b.size();x<m;x++){
			u32 c=b[x];
			for(i=j=k=0;i<1<<x;i++){
				while(s2[j]+c<s2[i])ts[k++]=s2[j++]+c;
				ts[k++]=s2[i];
			}
			while(j<1<<x)ts[k++]=s2[j++]+c;
			memcpy(s2,ts,(2<<x)<<3);
		}
		int l1=1<<a.size(),l2=1<<b.size();
		for(i=0,j=l2-1;i<l1;i++){
			while(j>0&&s1[i]+s2[j]>s)j--;
			if(s1[i]+s2[j]==s)break;
		}
		if(s1[i]+s2[j]!=s)return false;
		u64 l=s1[i],r=s2[j];
		u32 ml=0;
		if(l>0){
			s1[0]=0;
			for(x=0,m=a.size();x<m;x++){
				u32 c=a[x];
				for(i=0;i<1<<x;i++){
					s1[i|1<<x]=s1[i]+c;
					if(s1[i|1<<x]==l){ml=i|1<<x;x=m;break;}
				}
			}
		}
		u32 mr=0;
		if(r>0){
			s2[0]=0;
			for(x=0,m=b.size();x<m;x++){
				u32 c=b[x];
				for(i=0;i<1<<x;i++){
					s2[i|1<<x]=s2[i]+c;
					if(s2[i|1<<x]==r){mr=i|1<<x;x=m;break;}
				}
			}
		}
		return ml|((u64)mr<<a.size());
	}
}
u64 esi[N];

int main(){
#ifdef whzzt
	freopen("in.txt","r",stdin);
#endif
	srand(time(0)^size_t(new char));
	int i,j,D,x,y,e;
	// Input Paraneters
	gi(n),gi(m),gi(K);
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)gi(a[i][j]);
		
	dfs(1,1,n,m),dfs(1,1);
	u64 sum=0;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)sum+=a[i][j];
	for(i=1;i<=K;i++)esi[i]=sum/(K-i+1),sum-=esi[i];
	static const int GL=32;
	u64 lim=esi[K]+GL/2*5e8;
	reverse(L.begin(),L.end());
	for(D=1;D<=K;D++){
//		cerr<<D<<endl;
		vector<pii>in,out;u64 all=0; 
		while(all<lim&&L.size()){
			tie(x,y)=*L.rbegin(),L.pop_back(),ff[x][y]=true,all+=a[x][y],in.pb(pii(x,y)); 
			for(e=0;e<4;e++)if(!G[x+dx[e]][y+dy[e]]&&!ff[x+dx[e]][y+dy[e]]
			&&x+dx[e]>=1&&x+dx[e]<=n&&y+dy[e]>=1&&y+dy[e]<=m){
				ff[x+dx[e]][y+dy[e]]=true,all+=a[x+dx[e]][y+dy[e]],out.pb(pii(x+dx[e],y+dy[e]));
			}
		}
		vector<pii>loc;
		for(auto it:out)if(chk(it.fi,it.se))in.pb(it);else loc.pb(it);
		out.swap(loc),loc.clear();
		u64 mask;
		if(all>esi[D]){
			u64 c=all-esi[D];
			while(true){
				random_shuffle(out.begin(),out.end());
				vector<u32>w;
				u64 sum=0;
				for(i=0;i<min(GL,(int)out.size());i++)w.pb(a[out[i].fi][out[i].se]);
				for(auto a:w)sum+=a;
				if((sum/2-3e8<=c&&sum/2+3e8>=c)&&(mask=subsetsum::main(w,c))){
					while(out.size()>GL)in.pb(*out.rbegin()),out.pop_back();
					break;
				}
			}
		}else{
			while(out.size()>GL)in.pb(*out.rbegin()),out.pop_back();
			mask=0;
		}
		for(i=0;i<out.size();i++){
			if(mask>>i&1)tie(x,y)=out[i],ff[x][y]=false,all-=a[x][y];
			else in.pb(out[i]);
		}
		for(auto it:in)P[it.fi][it.se]=D;
	}
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)io::print(P[i][j]),io::putc(" \n"[j==m]);
	io::flush();
//	cerr<<clock()<<endl;
}