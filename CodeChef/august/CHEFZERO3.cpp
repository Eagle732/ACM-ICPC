#include<bits/stdc++.h>

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double llf;
typedef std::pair<int,int> pii;

#define xx first
#define yy second

template<typename T> inline T max(T a,T b){return a>b?a:b;}
template<typename T> inline T min(T a,T b){return a<b?a:b;}
template<typename T> inline T abs(T a){return a>0?a:-a;}
template<typename T> inline bool repr(T &a,T b){return a<b?a=b,1:0;}
template<typename T> inline bool repl(T &a,T b){return a>b?a=b,1:0;}
template<typename T> inline T gcd(T a,T b){T t;if(a<b){while(a){t=a;a=b%a;b=t;}return b;}else{while(b){t=b;b=a%b;a=t;}return a;}}
template<typename T> inline T sqr(T x){return x*x;}
#define mp(a,b) std::make_pair(a,b)
#define pb push_back
#define I inline
#define mset(a,b) memset(a,b,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))

#define fo0(i,n) for(int i=0,i##end=n;i<i##end;i++)
#define fo1(i,n) for(int i=1,i##end=n;i<=i##end;i++)
#define fo(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define fd0(i,n) for(int i=(n)-1;~i;i--)
#define fd1(i,n) for(int i=n;i;i--)
#define fd(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define foe(i,x)for(__typeof(x.end())i=x.begin();i!=x.end();++i)

struct Cg{I char operator()(){return getchar();}};
struct Cp{I void operator()(char x){putchar(x);}};
#define OP operator
#define RT return *this;
#define RX x=0;char t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;\
if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define RL if(t=='.'){lf u=0.1;for(t=P();t>='0'&&t<='9';t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x
#define RU x=0;char t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define TR *this,x;return x;
I bool IS(char x){return x==10||x==13||x==' ';}template<typename T>struct Fr{T P;I Fr&OP,(int&x)
{RX;if(f)x=-x;RT}I OP int(){int x;TR}I Fr&OP,(ll &x){RX;if(f)x=-x;RT}I OP ll(){ll x;TR}I Fr&OP,(char&x)
{for(x=P();IS(x);x=P());RT}I OP char(){char x;TR}I Fr&OP,(char*x){char t=P();for(;IS(t);t=P());if(~t){for(;!IS
(t)&&~t;t=P())*x++=t;}*x++=0;RT}I Fr&OP,(lf&x){RX;RL;RT}I OP lf(){lf x;TR}I Fr&OP,(llf&x){RX;RL;RT}I OP llf()
{llf x;TR}I Fr&OP,(uint&x){RU;RT}I OP uint(){uint x;TR}I Fr&OP,(ull&x){RU;RT}I OP ull(){ull x;TR}};Fr<Cg>in;
#define WI(S) if(x){if(x<0)P('-'),x=-x;char s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
#define WL if(y){lf t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)\
x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);
#define WU(S) if(x){char s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
template<typename T>struct Fw{T P;I Fw&OP,(int x){WI(10);RT}I Fw&OP()(int x){WI(10);RT}I Fw&OP,(uint x){WU(10);RT}
I Fw&OP()(uint x){WU(10);RT}I Fw&OP,(ll x){WI(19);RT}I Fw&OP()(ll x){WI(19);RT}I Fw&OP,(ull x){WU(20);RT}I Fw&OP()
(ull x){WU(20);RT}I Fw&OP,(char x){P(x);RT}I Fw&OP()(char x){P(x);RT}I Fw&OP,(const char*x){while(*x)P(*x++);RT}
I Fw&OP()(const char*x){while(*x)P(*x++);RT}I Fw&OP()(lf x,int y){WL;RT}I Fw&OP()(llf x,int y){WL;RT}};Fw<Cp>out;

#ifndef ONLINE_JUDGE
const bool debug=1;
#else
const bool debug=0;
#endif

#define rand rand_
#define fast __attribute__((optimize("-Ofast")))

typedef std::pair<int,ll> pil;

int timeStart;

fast inline lf realRunTime()
{
	return(lf)(clock()-timeStart)/CLOCKS_PER_SEC;
}

fast inline void resetRunTime()
{
	timeStart=clock();
}

struct Ran
{
	uint s;
	Ran():s(19260817){}
	Ran(uint x):s(x){}
	
	fast inline uint operator()()
	{
	    s^=s<<13;
	    s^=s>>17;
	    s^=s<<5;
	    return s;
	}
}rand;

fast inline ull rll()
{
	return ull(rand())<<32|rand();
}

template<typename T>fast inline void shuffle(T s,T t)
{
	int n=t-s;
	fd1(i,n-1)std::swap(s[i],s[rand()%(i+1)]);
}

const int N=1005;

int n,m,K,s[N][N],ans[N][N];
ll sum;

inline void input()
{
	in,n,m,K;
	fo1(i,n)fo1(j,m)in,s[i][j];
	sum=0;
	fo1(i,n)fo1(j,m)sum+=s[i][j];
}

inline void gen()
{
	n=rand()%501+500;
	m=rand()%501+500;
	K=rand()%501+500;
	sum=0;
	fo1(i,n)fo1(j,m)sum+=s[i][j]=rll()%1000000000+1;
	//out,"sum:",sum,'\n';
}

inline void output()
{
	fo1(i,n){fo1(j,m)out,ans[i][j],' ';out,'\n';}
}

namespace _s
{
	bool vis[N][N],vc[N];
	ll sum[N];
	
	inline void dfs(int x,int y)
	{
		vis[x][y]=1;
		sum[ans[x][y]]+=s[x][y];
		#define work(px,py) if(!vis[px][py]&&ans[px][py]==ans[x][y])dfs(px,py)
		work(x+1,y);work(x-1,y);work(x,y+1);work(x,y-1);
		#undef work
	}
	
	inline lf score()
	{
		fo1(i,n)fo1(j,m)if(ans[i][j]<1||ans[i][j]>K)return -1;
		fo1(i,n)fo1(j,m)vis[i][j]=0;
		fo1(i,K)vc[i]=0,sum[i]=0;
		fo1(i,n)fo1(j,m)
		{
			if(!vis[i][j])
			{
				if(vc[ans[i][j]])out,"not connected:",ans[i][j],'\n';
				if(vc[ans[i][j]])return -2;
				vc[ans[i][j]]=1;
				dfs(i,j);
			}
		}
		fo1(i,K)if(!vc[i])return -3;
		ll mi=1e18,ma=-1e18;
		//fo1(i,K)out,sum[i],' ';out,'\n';
		fo1(i,K)repl(mi,sum[i]),repr(ma,sum[i]);
		//out,ma-mi,'\n';
		return(ma-mi)*1e9/::sum;
	}
}
using _s::score;

inline void solve0()
{
	ll t=sum/K,p=0;
	int c=1,x=1,y=1;
	for(;x<=n;)
	{
		p+=s[x][y];
		ans[x][y]=c;
		//if(p>t)out,x,' ',y,' ',c,' ',K,'\n';
		if(p>t)c=min(c+1,K),p=s[x][y];
		if(x&1)y++;else y--;
		if(y==m+1)x++,y--;
		if(y==0)x++,y++;
	}
}

namespace solve1
{
	int c,s[N*N];
	
	inline bool chk(ll lim)
	{
		ll os=0;
		int r=1;
		fo1(i,c)
		{
			if(os+s[i]>lim)r++,os=0;
			os+=s[i];
		}
		//out,"chk:",lim,' ',r,' ',K,'\n';
		return r<=K;
	}
	
	inline void solve()
	{
		int x=1,y=1;
		for(c=0;x<=n;)
		{
			s[++c]=::s[x][y];
			if(x&1)y++;else y--;
			if(y==m+1)x++,y--;
			if(y==0)x++,y++;
		}
		//out,'/',c,' ',sum,'\n';
		ll t=sum/K-1,l=0,r=1;
		while(!chk(t+r))r<<=1;
		while(l+1<r)
		{
			ll mid=(l+r)>>1;
			if(chk(t+mid))r=mid;
			else l=mid;
		}
		//out,t,' ',l,' ',r,'\n';
		t+=r;ll p=0;
		c=1,x=1,y=1;
		for(;x<=n;)
		{
			p+=::s[x][y];
			if(p>t)c++,p=::s[x][y];
			ans[x][y]=c;
			if(x&1)y++;else y--;
			if(y==m+1)x++,y--;
			if(y==0)x++,y++;
		}
		//out,c,' ',K,'\n';
	}
}

namespace pack
{
	const int M=4233333,max_iters=40;
	
	int fe,ge,s[N],fc[N],gc[N];
	ll buf[M],*be,*f[N],*g[N];
	bool ef[N],sel[N];
	
	inline int extend_pack(ll*s,int c,ll x)
	{
		int i=0,j=0,k=0;
		for(;i<c;i++)
		{
			for(;j<c&&s[j]<=s[i]+x;j++)
				be[k++]=s[j];
			if(!k||be[k-1]!=s[i]+x)
				be[k++]=s[i]+x;
		}
		return k;
	}
	
	inline pii dec(ll*s,int c,ll x,ll v)
	{
		fo0(i,c)
		{
			if(s[i]==v)return mp(i,0);
			if(s[i]+x==v)return mp(i,1);
		}
		assert(0);
	}
	
	inline ll min_dis(ll*f,int fc,ll*g,int gc,ll req)
	{
		int i=0,j=gc-1;
		ll res=1e18;
		for(;i<fc;i++)
		{
			for(;~j&&g[j]+f[i]>req;j--)
				repl(res,g[j]+f[i]-req);
			if(~j)repl(res,req-g[j]-f[i]);
			if(j+1<gc)repl(res,g[j+1]+f[i]-req);
		}
		return res;
	}
	
	inline void find_min(ll*f,int fc,ll*g,int gc,ll req,int&rf,int&rg)
	{
		int i=0,j=gc-1;
		ll res=1e18;
		for(;i<fc;i++)
		{
			for(;~j&&g[j]+f[i]>req;j--)
				if(repl(res,g[j]+f[i]-req))rf=i,rg=j;
			if(~j)if(repl(res,req-g[j]-f[i]))rf=i,rg=j;
			if(j+1<gc)if(repl(res,g[j+1]+f[i]-req))rf=i,rg=j+1;
		}
	}
	
	bool naive_flag;
	
	inline int solve(int*_s,int n,ll target,int*res,int rem_times=4)
	{
		naive_flag=0;
		//out,"solve:",n,' ',target/int(5e8),'\n';
		fo0(i,n)s[i]=_s[i];
		be=buf;
		*be=0;
		f[0]=be++;
		fc[0]=1;
		fe=0;
		*be=0;
		g[0]=be++;
		gc[0]=1;
		ge=0;
		int iters=min(n,max_iters);
		fo0(i,iters)
		{
			int t;
			if(fc[fe]<=gc[ge])
			{
				ef[i]=1;
				t=extend_pack(f[fe],fc[fe],s[i]);
				f[++fe]=be;
				be+=fc[fe]=t;
			}
			else
			{
				ef[i]=0;
				t=extend_pack(g[ge],gc[ge],s[i]);
				g[++ge]=be;
				be+=gc[ge]=t;
			}
			//out,fe,' ',ge,' ',fc[fe],' ',gc[ge],' ',min_dis(f[fe],fc[fe],g[ge],gc[ge],target),'\n';
			if(!min_dis(f[fe],fc[fe],g[ge],gc[ge],target))
			{
				iters=i+1;break;
			}
		}
		int fp,gp;
		find_min(f[fe],fc[fe],g[ge],gc[ge],target,fp,gp);
		if(f[fe][fp]+g[ge][gp]!=target)
		{
			if(rem_times&&n>=max_iters*2)
			{
				int t=solve(_s+max_iters,n-max_iters,target,res,rem_times-1);
				fo0(i,t)res[i]+=max_iters;
				return t;
			}
			naive_flag=1;
			if(debug)out,"naive\n";
		}
		//out,'/',fp,' ',gp,'\n';
		fd0(i,iters)
		{
			pii t;
			if(ef[i])
			{
				t=dec(f[fe-1],fc[fe-1],s[i],f[fe][fp]);
				fe--;
				sel[i]=t.yy;
				fp=t.xx;
			}
			else
			{
				t=dec(g[ge-1],gc[ge-1],s[i],g[ge][gp]);
				ge--;
				sel[i]=t.yy;
				gp=t.xx;
			}
		}
		//fo0(i,iters)out,sel[i],' ';out,'\n';
		//ll ts=0;fo0(i,iters)if(sel[i])ts+=s[i];out,ts,'\n';
		//exit(3);
		int rc=0;
		fo0(i,iters)if(sel[i])res[rc++]=i;
		return rc;
	}
}

namespace solve2
{
	const int SCNT=20,COL_CNT=20,SCNTL=60,_max_times=1000000;
	const ll V=5e8;
	
	ll lim,psum,bsum[N];
	bool v[N][N];
	int cur_line,min_extend,max_times,rs[N],rsb[N];
	
	inline int cnt(int x,int l,int r)
	{
		int c=0;
		fo(i,l,r)if(!v[x][i])c++;
		return c;
	}
	
	inline ll rsum(int x,int l,int r)
	{
		ll su=0;
		fo(i,l,r)if(!v[x][i])su+=s[x][i];
		return su;
	}
	
	inline pil cntsum(int x,int l,int r)
	{
		int c=0;ll su=0;
		fo(i,l,r)if(!v[x][i])c++,su+=s[x][i];
		return mp(c,su);
	}
	
	inline pil get_min_extend(int l,int r)
	{
		ll su=0;
		for(int i=cur_line;i<=n;i++)
		{
			pil t=cntsum(i,l,r);
			su+=t.yy;
			if(t.xx==r-l+1&&i>=min_extend)return mp(i,su);
		}
		assert(0);
	}
	
	inline void fill(int x,int xr,int l,int r,int qa)
	{
		fo(i,x,xr)fo(j,l,r)if(!v[i][j])
		{
			v[i][j]=1,ans[i][j]=qa,bsum[qa]+=s[i][j];
		}
	}
	
	inline void updRt()
	{
		if(realRunTime()>4.5)max_times=1000;
	}
	
	inline int random_find(int x,int l,int r,ll vl,ll vr)
	{
		//out,"random_find:",l,' ',r,' ',vl,' ',vr,' ',vr/int(5e8),'\n';
		int*e=s[x]+l,n=r-l+1;
		fo0(i,n)rs[i]=i;
		ll best=-1e18;
		int bc;
		for(int i=0;i<max_times;i++)
		{
			if((i+1)%131072==0)updRt();
			ll ts=0;
			uint os=rand.s;
			fo0(j,n)
			{
				std::swap(rs[j],rs[rand()%(n-j)+j]);
				ts+=e[rs[j]];
				if(ts>vr)break;
				if(ts>=vl)
				{
					fo(k,0,j)rs[k]+=l;
					return j+1;
				}
				if(ts>best)
				{
					best=ts;
					bc=j+1;
					fo(k,0,j)rsb[k]=rs[k];
				}
			}
		}
		//out,"random_find_lst\n";
		//out,vl,' ',vr,' ',best,' ',bc,'\n';
		fo0(k,bc)rs[k]=rsb[k]+l;
		return bc;
	}
	
	inline int pack_find(int x,int l,int r,ll vl,ll vr)
	{
		int t=pack::solve(s[x]+l,r-l+1,(vl+vr)/2,rs);
		fo0(i,t)rs[i]+=l;
		return t;
	}
	
	inline void _select(ll vl,ll vr,int id,int _t)
	{
		int t,tr,tre,sc;
		pil sel;
		for(sc=SCNT;;sc--)
		{
			if(sc<=16)return _select(vl,vr,id,rand()%m+1);
			assert(sc);
			for(min_extend=cur_line;;min_extend++)
			{
				//out,"min_extend:",min_extend,'\n';
				tr=t=_t;
				for(;tr<=m&&(sel=get_min_extend(t,tr)).yy<vr-V*sc;tr++);
				//out,'/',t,' ',get_min_extend(t,m).yy,' ',vr-V*sc,'\n';
				if(tr>m)
				{
					tr=m;
					for(;t&&(sel=get_min_extend(t,tr)).yy<vr-V*sc;t--);
					if(t&&(sel.yy<vr-V*(sc-3)||(sel.xx>cur_line&&tr-t>=40&&sel.yy-V*(tr-t-40)<vr-V*sc&&cnt(sel.xx-1,t,tr)==tr-t+1)))break;
				}else if(sel.yy<vr-V*(sc-3)||(sel.xx>cur_line&&tr-t>=40&&sel.yy-V*(tr-t-40)<vr-V*sc&&cnt(sel.xx-1,t,tr)==tr-t+1))break;
			}
			sel=get_min_extend(t,tr);
			tre=tr;
			while(sel.yy>vr-V*(sc-3))
			{
				sel.yy-=s[sel.xx][tre];
				tre--;
			}
			//out,'/',sc,' ',V*sc,'\n';
			//out,vr,'\n',vr-V*sc,'\n',sel.yy,'\n';
			assert(sel.xx<n);
			if(rsum(sel.xx+1,t,tre)>=V*sc*2)break;
		}
		//out,n,' ',id,' ',sc,' ',cur_line,' ',sel.xx,' ',t,' ',tr,' ',tre,' ',vl-sel.yy,' ',vr-sel.yy,'\n';
		//int uc=random_find(sel.xx+1,t,tr,vl-sel.yy,vr-sel.yy);
		int uc=pack_find(sel.xx+1,t,tre,vl-sel.yy,vr-sel.yy);
		fill(cur_line,sel.xx-1,t,tr,id);
		fill(sel.xx,sel.xx,t,tre,id);
		if(0)
		{
			freopen("out.txt","w",stdout);
			fo1(i,n){fo1(j,m)printf("%4d",ans[i][j]);out,'\n';}
			exit(4);
		}
		fo0(i,uc)
		{
			v[sel.xx+1][rs[i]]=1;
			ans[sel.xx+1][rs[i]]=id;
			bsum[id]+=s[sel.xx+1][rs[i]];
		}
		//out,bsum[id],' ',vl,' ',vr,'\n';
		//assert(bsum[id]==vr);
	}
	
	inline void select(ll vl,ll vr,int id)
	{
		int t;
		t=1;
		while(v[cur_line][t])t++;
		_select(vl,vr,id,t);
	}
	
	int rp[N],rpo[N],tp[N],tpb[N],tps[N*SCNT];
	
	inline int cntc(int x,int l,int r)
	{
		int c=0;
		fo(i,l,r)if(!v[i][x])c++;
		return c;
	}
	
	inline ll sumc(int x,int l,int r)
	{
		ll ts=0;
		fo(i,l,r)if(!v[i][x])ts+=s[i][x];
		return ts;
	}
	
	inline void _select_lst(ll vl,ll vr,int id)
	{
		//out,"select_lst:",vl,' ',vr,' ',id,'\n';
		ll ts=0;int p=0;
		while(ts<vr-V*SCNTL)
		{
			++p;
			ts+=sumc(p,cur_line,n);
		}
		vl-=ts,vr-=ts;
		//out,p,' ',ts,' ',vl,' ',vr,'\n';
		int u=min(m-p,SCNTL*4),tc=0;
		//fo(i,cur_line,n)fo0(j,u)tps[tc++]=i;
		//fo(i,max(n-1,cur_line),n)fo0(j,u)tps[tc++]=i;
		int ut=n;ts=0;
		while(ut>=cur_line)
		{
			if(cnt(ut-1,p+1,p+u)!=u)break;
			fo0(j,u)
			{
				tps[tc++]=ut;
				if(!v[ut][p+j])ts+=s[ut][p+j];
			}
			//if(ts>vr*7)break;
			ut--;
		}
		//out,cur_line,' ',ut,' ',n,' ',ts,' ',vr,'\n';
		ll best=-1e18;
		uint bseed;
		for(int i=0;i<max_times;i++)
		{
			if((i+1)%32768==0)updRt();
			ts=0;
			uint os=rand.s;
			fo(j,cur_line,n)tp[j]=p;
			fo0(j,tc)
			{
				std::swap(tps[j],tps[rand()%(tc-j)+j]);
				int x=tps[j];
				++tp[x];
				if(!v[x][tp[x]])
				{
					ts+=s[x][tp[x]];
					if(ts>vr)break;
					if(ts>=vl)
					{
						fo(k,cur_line,n)
						{
							fo(l,rp[k]+1,tp[k])if(!v[k][l])
							{
								v[k][l]=1;
								ans[k][l]=id;
								bsum[id]+=s[k][l];
							}
							rp[k]=tp[k];
						}
						return;
					}
					if(ts>best)
					{
						best=ts;
						fo(k,cur_line,n)tpb[k]=tp[k];
					}
				}
			}
		}
		//out,"_select_lst_lst\n";
		fo(k,cur_line,n)
		{
			fo(l,rp[k]+1,tpb[k])if(!v[k][l])
			{
				v[k][l]=1;
				ans[k][l]=id;
				bsum[id]+=s[k][l];
			}
			rp[k]=tpb[k];
		}
	}
	
	int cbid,connt,connv[N][N];
	int(*chk)(int,int);
	
	int chk1(int x,int y){return ans[x][y]==cbid;}
	int chk2(int x,int y){return v[x][y]==0;}
	
	inline void dfsc(int x,int y)
	{
		connv[x][y]=connt;
		#define work(px,py) if(connv[px][py]!=connt&&chk(px,py))dfsc(px,py)
		if(x>1)work(x-1,y);
		if(x<n)work(x+1,y);
		if(y>1)work(x,y-1);
		if(y<m)work(x,y+1);
	}
	
	inline bool chkconn()
	{
		connt++;
		bool flag=0;
		fo(i,cur_line,n)fo1(j,m)if(chk(i,j)&&connv[i][j]!=connt)
		{
			if(flag)return 0;
			flag=1;
			dfsc(i,j);
		}
		return 1;
	}
	
	inline void select_lst(ll vl,ll vr,int id)
	{
		//out,"=========\n";
		while(1)
		{
			fo(i,cur_line,n)rpo[i]=rp[i];
			_select_lst(vl,vr,id);
			chk=chk1,cbid=id;
			bool fa=chkconn();
			chk=chk2;
			bool fb=chkconn();
			//out,id,' ',fa,' ',fb,'\n';
			if(0)
			{
				freopen("out.txt","w",stdout);
				fo1(i,n){fo1(j,m)printf("%4d",ans[i][j]);out,'\n';}
				exit(7);
			}
			if(fa&&fb)return;
			fo(i,cur_line,n)rp[i]=rpo[i];
			fo(i,cur_line,n)fo1(j,m)if(ans[i][j]==id)
			{
				ans[i][j]=0;
				v[i][j]=0;
				bsum[id]-=s[i][j];
			}
		}
	}
	
	pii tpo[N];
	
	inline void select_lst2(ll vl,ll vr,int id,int scn=SCNTL)
	{
		//int rp[N],rpo[N],tp[N],tpb[N],tps[N*SCNT];
		//out,"select_lst:",vl,' ',vr,' ',id,'\n';
		ll ts=0;int p=0;
		while(ts<vr-V*(scn+n-cur_line))
		{
			++p;
			ts+=sumc(p,cur_line,n);
		}
		//out,n,' ',p+1,'\n';
		//assert(!v[n][p+1]);
		ll ots=ts;
		vl-=ts,vr-=ts;
		int tu=min(SCNTL*2,m-p);
		tp[p-1]=n-cur_line+1;
		fo(i,p,p+tu)
		{
			for(tp[i]=1;!v[n-tp[i]][i];tp[i]++);
			repl(tp[i],tp[i-1]);
		}
		//fo(i,p+1,p+tu)out,tp[i],' ';out,'\n';
		int tc=0,op=p;ts=0;
		//out,id,' ',p,' ',tc,' ',ts,' ',vr,' ',vr-V*SCNT,'\n';
		if(0)
		{
			freopen("out.txt","w",stdout);
			fo1(i,n){fo1(j,m)printf("%4d",ans[i][j]);out,'\n';}
			exit(8);
		}
		while(tc<pack::max_iters||ts<vr-V*SCNT)
		{
			++p;
			if(p>m)break;
			fo1(i,tp[p+1]/3)if(tc<pack::max_iters||ts<vr-V*SCNT)
			{
				ts+=s[n-i*3+3][p];
				tpb[tc]=s[n-i*3+2][p];
				tpo[tc++]=mp(n-i*3+2,p);
			}
		}
		//out,p,' ',tc,' ',ts,' ',vr,' ',vr-V*SCNT,' ',vr-ts,'\n';
		//if(vr-ts<V*(SCNT-4))out,"recursive\n";
		if(vr-ts<V*(SCNT-4))return select_lst2(vl+ots,vr+ots,id,scn+5);
		fo0(i,tc)
		{
			int x=tpo[i].xx+1,y=tpo[i].yy;
			v[x][y]=1;
			ans[x][y]=id;
			bsum[id]+=s[x][y];
		}
		fo(i,cur_line,n)fo1(j,op)if(!v[i][j])
		{
			v[i][j]=1;
			ans[i][j]=id;
			bsum[id]+=s[i][j];
		}
		assert(p<=m);
		//if(p>m)out,"================\n";
		vl-=ts,vr-=ts;
		int sz=pack::solve(tpb,tc,vr,rpo);
		fo0(i,sz)
		{
			int x=tpo[rpo[i]].xx,y=tpo[rpo[i]].yy;
			v[x][y]=1;
			ans[x][y]=id;
			bsum[id]+=s[x][y];
		}
		//out,bsum[id],'\n';
	}
	
	inline void solve()
	{
		lim=0;
		max_times=_max_times;
		//out,lim,'\n';
		fo1(i,n)fo1(j,m)v[i][j]=0,ans[i][j]=0;
		cur_line=1;
		fo1(i,K)bsum[i]=0;
		psum=0;
		fo1(bid,K-COL_CNT)
		{
			while(!cnt(cur_line,1,m))cur_line++;
			//out,"=====",bid,' ',n,' ',cur_line,' ',cnt(cur_line,1,m),'\n';
			//psum+this>=sum*i/K-lim <=sum*i/K-lim
			ll curl=sum*bid/K-lim-psum,curr=curl+lim*2;
			select(curl,curr,bid);
			psum+=bsum[bid];
			//if(bid==10)exit(4);
		}
		//out,"ok\n";
		//freopen("out.txt","w",stdout);
		//fo1(i,n){fo1(j,m)printf("%4d",ans[i][j]);out,'\n';}
		//exit(9);
		fo(i,cur_line,n)rp[i]=0;
		fo(bid,K-COL_CNT+1,K-1)
		{
			ll curl=sum*bid/K-lim-psum,curr=curl+lim*2;
			select_lst2(curl,curr,bid);
			psum+=bsum[bid];
		}
		fo1(i,n)fo1(j,m)if(!ans[i][j])ans[i][j]=K,bsum[K]+=s[i][j];
		ll mi=1e18,ma=-1e18;
		fo1(i,K)repl(mi,bsum[i]),repr(ma,bsum[i]);
		//fo1(i,K)out,bsum[i],' ';out,'\n';
		if(debug)out,ma-mi,'\n';
		assert(bool(sum%K)==ma-mi);
		//freopen("out.txt","w",stdout);
		//fo1(i,n){fo1(j,m)printf("%4d",ans[i][j]);out,'\n';}
		//exit(3);
	}
}

inline void solve()
{
	return solve2::solve();
	solve0();
}

fast inline void test()
{
	int cnt=0;lf sum=0;
	while(1)
	{
		cnt++;
		resetRunTime();
		out,rand.s,'\n';
		gen();
		solve();
		lf t=score();
		if(t<-.5||t>7e-6)out,"================================\n";
		sum+=t;
		printf("%d %.9lf sum=%.9lf avg=%.9lf time=%.2lfs\n",cnt,t,sum,sum/cnt,realRunTime());
		if(realRunTime()>7)while(1);
	}
}

#ifndef ONLINE_JUDGE
int main()
{
	//rand.s=19260821;
	test();
	//input();
	rand.s=3680378927;
	gen();
	solve();
	lf t=score();
	printf("%.9lf\n",t);
	//output();
}
#else
int main()
{
	input();
	solve();
	output();
}
#endif