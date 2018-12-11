#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll unsigned long long
int MAX_MAT=63;
ll T,N;
template<typename T>
class MATRIX{
	public :
		vector<vector<ll> >matrix; 
		T row,col;
	
		MATRIX(){};
		MATRIX(T a,T b);
		
		void toIdentity(T m);
		~MATRIX(){};

		void init();
		void printMat();

		const MATRIX operator * (const MATRIX&) const;

		MATRIX &operator=(const MATRIX&);
};
	MATRIX<ll >M_powers[65];

	// Default constructor
	template<typename T>
	MATRIX<T> ::MATRIX(T m,T n)
	{
		this->row = m;
		this->col = n;
		vector<vector<ll> > values(m,vector<ll>(n,0));
		matrix=values;
	}

	// Initialized to Identity matrix
	template<typename T>
	void MATRIX<T> ::toIdentity(T m)
	{
		this->row = m;
		this->col = m;
		vector<vector<ll> > values(m,vector<ll>(m,0));
		for(int i=0;i<m;i++)
		{
			values[i][i] = 1;
		}
		matrix=values;
		return ;
	}


	// Initialization
	template<typename T>
	void MATRIX<T> ::init()
	{
		this->row = this->col = 3;
		vector<vector<ll> >values(this->row,vector<ll>(this->col,1));
		matrix = values;

		matrix[0][0] = 0;
		matrix[0][1] = 1;
		matrix[0][2] = 0;
		matrix[1][0] = 0;
		matrix[1][1] = 0;
		matrix[1][2] = 1;
		matrix[2][0] = 1;
		matrix[2][1] = 1;
		matrix[2][2] = 1;
		
		return ;
	}

	// Overloaded constructor
	template<typename T>
	const MATRIX<T> MATRIX<T>::operator * (const MATRIX& matB) const
	{	
		MATRIX<ll> matRes = MATRIX<ll>((int)this->row,(int)matB.col);
		
		for(int i=0;i<this->row;i++)
		{
			for(int j=0;j<matB.col;j++)
			{
				for(int k=0;k<this->col;k++){
					matRes.matrix[i][j] += this->matrix[i][k] * matB.matrix[k][j];		
					matRes.matrix[i][j] %= MOD;
				}
			}
			// cout<<endl;
		}	
		return matRes;	
	}



	// Overloaded Assignment operator
	template<typename T>  
	MATRIX<T>& MATRIX<T>::operator = (const MATRIX& right)
	{
		this->matrix = right.matrix;
		this->row = right.row;
		this->col = right.col;
		return *this;
	}


	void precalc_powers(MATRIX<ll > M)
	{
		M_powers[0] = M;
		for (int i = 1; i < MAX_MAT; ++i)
		{
			M_powers[i] = M_powers[i-1] * M_powers[i-1]; 
		}
	}
	template<typename T>
	void MATRIX<T>::printMat()
	{
		for(int i=0;i<this->row;i++)
		{
 			for(int j=0;j<this->col;j++)
			{
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
		return ;
	}
	void calculate(MATRIX<ll> &result,ll n)
	{
		ll i=0;
		while(n)
		{
			if(n & 1)
			{
				result = result * M_powers[i];
			}
			i++;
			n >>= 1;
		}
		return ;
	}
MATRIX<ll>result = MATRIX<ll>();
ll ModularExponent(ll n,ll N){
	if(N == 0){
		return 1;
	}else if(N%2 == 0){
		return ModularExponent((n*n)%MOD,N/2);
	}else{
		return (n*ModularExponent((n*n)%MOD,(N-1)/2))%MOD;
	}
}
long long ans;
int main()
{	

	MATRIX<ll> first  = MATRIX<ll>();
 	first.init();
 	MATRIX<ll> second  = MATRIX<ll>(3,1);
 	second.matrix[0][0] = 1;
 	second.matrix[1][0] = 2;
 	second.matrix[2][0] = 3;
 	
 	precalc_powers(first);
 	// M_powers[59].printMat();
    cin>>T;
 	for(ll n=0;n<T;n++){
 		cin>>N;
 			result.toIdentity(first.row);
	 		calculate(result,N+1);
	 		result = result*second;
	 		cout<<result.matrix[2][2];
	 		
 		cout<<endl;
 	}


 
	return 0;
}