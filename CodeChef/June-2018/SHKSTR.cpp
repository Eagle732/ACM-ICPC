#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define vec ((temp->children[str[i] - 'a'])->ID)
using namespace std;
struct node{
	struct node *children[27];
	vector<int>ID;
	bool end;
	int start;
};
typedef struct node Node;

Node *newNode(int A){
	Node* temp = (Node*)malloc(sizeof(Node));
	for(int i=0;i<27;i++){
		temp->children[i] = NULL;
	}
	temp->ID.push_back(A);
	temp->end = false;
	temp->start = 100000;
	return temp;
}

bool available(vector<int >arr,int index){
	if(arr[0] <= index){
			return true;
		}else{
			return false;
		}
}



void insert(Node **root,int A,string str,int index){
	Node* temp;
	temp = *root;
	for(int i=0;i<str.length();i++){
		if(temp->children[str[i] - 'a'] == NULL)
			temp->children[str[i] - 'a'] = newNode(A);
		temp = temp->children[str[i] - 'a'];
	}
	temp->end = true;
	temp->start = index;
}

void traverse(Node *root,string str){
	if(root == NULL){
		return ;
	}

	for(int i=0;i<26;i++){
		if(root->children[i] != NULL){

			if(root->children[i]->end == true){
				cout<<str+((char)(i+'a'))<<endl;;
			}
			traverse(root->children[i],str+(char)('a'+i));
		}
	}
}



void search(Node* root,string str,int index){
	string s="";
	Node* temp = root;
	int i;
	for( i=0;i<str.length();i++){
		if((temp->children[str[i] - 'a'] != NULL )){
			if(available(temp->children[str[i] - 'a']->ID,index)){
				temp = temp->children[str[i] -'a'];
				s += str[i];
			}else{
				break;
			}
		}else
			break;
	}
	int n = 10 - i+1;
	while(n--){
		if(temp->end == true){
			if(temp->start <= index){
				break;
			}
		}
		for(int i=0;i<26;i++){
			if(temp->children[i] != NULL){
				if(available(temp->children[i]->ID,index)){
					s += (char)(i+'a');
					temp = temp->children[i];
					break;
				}
			}
		}
	}
	cout<<s<<endl;
}
int main(){
	int N,A,index;
	string str;
	cin>>N;

	Node* root = (Node*)malloc(sizeof(Node));
	while(index++ < N){
		cin>>str;
		insert(&root,index,str,index);
	}
	cin>>N;
	while(N--){
		cin>>A>>str;
		search(root,str,A);
	}
	return 0;
}
