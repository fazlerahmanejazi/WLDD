#include <bits/stdc++.h>

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define inf INT_MAX
#define minf INT_MIN

typedef long long int lli;

using namespace std;

ofstream outfile;
ifstream infile;

#define maxtriesize 10
struct mytrie{
	struct mytrie *left; //left = 0
	struct mytrie *right;//right = 1
};

struct mytrie *head;

void insert(string s){
	struct mytrie *temp, *node = head;
	for(int i = 0; i < maxtriesize; ++i){
		if(s[i] == '0'){
			if(node->left == NULL){
				temp = (struct mytrie *)malloc(sizeof(struct mytrie));
				temp->left = NULL;
				temp->right = NULL;
				node->left = temp;
			}
			node = node->left;
		}else{
			if(node->right == NULL){
				temp = (struct mytrie *)malloc(sizeof(struct mytrie));
				temp->left = NULL;
				temp->right = NULL;
				node->right = temp;
			}
			node = node->right;
		}
	}
	return ;
}

lli query(string s){
	lli ans = 0;
	struct mytrie *node = head;
	for(int i = 0; i < maxtriesize; ++i){
		ans *= 2;
		if(s[i] == '0'){
			if(node->right == NULL){
				node = node->left;
			}else{
				ans++;
				node = node->right;
			}
		}else{
			if(node->left == NULL){
				node = node->right;
			}else{
				ans++;
				node = node->left;
			}
		}
	}
	return ans;
}
void create_trie(){
	head = (struct mytrie *)malloc(sizeof(struct mytrie));
	head->left = NULL;
	head->right = NULL;
}

void insert(lli x){
	string s = "", fin = "";int n = 0;
	while(x){
		n++;
		s += (x%2+'0');
		x /= 2;
	}
	reverse(s.begin(), s.end());
	for(int i = n+1; i <= maxtriesize; ++i)
		fin += "0";

	fin += s;
	insert(fin);
}



lli query(lli x){
	string s = "", fin = "";int n = 0;
	while(x){
		n++;
		s += (x%2+'0');
		x /= 2;
	}
	reverse(s.begin(), s.end());
	for(int i = n+1; i <= maxtriesize; ++i)
		fin += "0";

	fin += s;
	return query(fin);
}

void delete_trie(struct mytrie *node){
	if(node == NULL)
		return ;
	struct mytrie *left = node->left, *right = node->right;
	free(node);
	delete_trie(left);
	delete_trie(right);
}


int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	create_trie();
	
}