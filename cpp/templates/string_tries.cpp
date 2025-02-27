struct node {
	node *child[26];
	// unordered_map<int,node*>;
	// unordered_map<char,node*>;
	int prefix;
	vector<string> wend;
	node() {
		prefix=0;
		for(int i=0;i<26;++i){
			child[i]=NULL;
		}
	}
}

struct trie {
	node* root;
	trie() {
		root=new node;
	}
}

void insert(string s){
	node* curr=root;
	for(int i=0;i<s.size();++i){
		curr->prefix++;
		int x=s[i]-'a';
		if(curr->child[x]==NULL){
			curr->child=new node;
		}
		curr=curr->child;
	}
	curr->wend.push_back(s);
}

void delete(string s){
	node* curr=root;
	for(int i=0;i<s.size();++i){
		curr->prefix--;
		int x=s[i]-'a';
		if(curr->child[x]==NULL){
			curr->child=new node;
		}
		curr=curr->child;
	}
	curr->wend.pop_back();
}