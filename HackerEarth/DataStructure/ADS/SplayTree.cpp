#include<bits/stdc++.h>
using namespace std;
template<typename T,typename Comp = std::less<T>>
class splay_tree{
private:
	Comp comp;
	unsigned long p_size;
	struct node{
		node *left,*right;
		node *parent;
		T key;
		node(const T& init = T()) : left(nullptr),right(nullptr),parent(nullptr),key(init){}
		~node()
		{

		}
	}*root;

	void left_rotate(node *x){
		node *y = x->right;
		if(y)
		{
			
		}
	}





}




int main()
{




	return 0;
}