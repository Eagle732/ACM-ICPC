#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll unsigned long long
int MAX_MAT=55;
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
		const MATRIX operator + (const MATRIX&) const;

		MATRIX &operator=(const MATRIX&);
};
	MATRIX<ll >M_powers[55];

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
		// cin>>this->row>>this->col;
		this->row = this->col = 2;
		vector<vector<ll> >values(this->col,vector<ll>(this->row,1));
		matrix = values;
		// int a = 1;
		// for(int i=0;i<this->row;i++)
		// {
		// 	for(int j=0;j<this->col;j++)
		// 	{
		// 		// cin>>a;
		// 		matrix[i][j] = 1;
		// 	}
		// }
		matrix[0][0] = 0;
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
		}	
		return matRes;	
	}

	template<typename T>
	const MATRIX<T> MATRIX<T>::operator + (const MATRIX& matB) const
	{	
		MATRIX<ll> matRes = MATRIX<ll>((int)this->row,(int)matB.col);
		for(int i=0;i<this->row;i++)
		{
			for(int j=0;j<matB.col;j++)
			{
				matRes.matrix[i][j] = this->matrix[i][j] + matB.matrix[i][j];
				matRes.matrix[i][j] %= MOD;
			}
		}	
		return matRes;	
	}

	// Show the contents of matrix
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

	// Overloaded Assignment operator
	template<typename T>  
	MATRIX<T>& MATRIX<T>::operator = (const MATRIX& right)
	{
		this->matrix = right.matrix;
		this->row = right.row;
		this->col = right.col;
		return *this;
	}

	void fast_exponential(MATRIX<ll> &result,MATRIX<ll >D,int power)
	{
		result.toIdentity(D.row);
		while(power)
		{
			if(power & 1)
			{
				result = result * D;
				result.printMat();
			}
			cout<<"DI : \n";
			D.printMat();
			D  = D*D;
			cout<<"D\n ";
			D.printMat();
			power >>= 1;
		}
		return ;
	}

	void precalc_powers(MATRIX<ll > M)
	{
		M_powers[0] = M;
		for (int i = 1; i < MAX_MAT; ++i)
		{
			M_powers[i] = M_powers[i-1] * M_powers[i-1]; 
		}
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
int main()
{	
	
	cin>>T;
	MATRIX<ll> first  = MATRIX<ll>();
 	first.init();
 	// first.printMat();
 	precalc_powers(first);
 	// M_powers[58].printMat();
 	
 	for(int n=0;n<T;n++){
 		cin>>N;
 		cout<<N<<endl;
 		result.toIdentity(first.row);
 		calculate(result,N+1);
 		cout<<result.matrix[1][1];
 		cout<<endl;
 	}

	return 0;
}