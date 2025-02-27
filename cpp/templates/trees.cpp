#include <bits/stdc++.h>
using namespace std;

// O(n) space
bool lca_bin_tree(TreeNode*node,TreeNode*target,vector<TreeNode*>&path){
    if(node==NULL)return 0;
    path.push_back(node);
    if(node==target)return 1;
    bool left=lca(node->left,target,path),right=lca(node->right,target,path);
    bool res=left||right;
    if(!res)path.pop_back();
    return res;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*>path,ppath,qpath;
    lca(root,p,ppath);
    lca(root,q,qpath);
    TreeNode* res;
    for(int i=0;i<ppath.size()&&i<qpath.size()&&ppath[i]==qpath[i];++i)res=ppath[i];
    return res;
}

// O(1) space
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL||root==p||root==q)return root;
    TreeNode* right=lowestCommonAncestor(root->right,p,q);
    TreeNode* left=lowestCommonAncestor(root->left,p,q);
    if(left!=NULL&&right!=NULL)return root;
    return (left!=NULL)?left:right;
}


vector<int> get_height(int root=0,vector<vector<int>> &adj){
    vector<int>height(n,0);
    function<void> dfs=[&](int node,int par=-1){
        for(auto &neigh:adj[node]){
            if(neigh==par)continue;
            dfs(child,node);
            height[node]=max(height[node],height[neigh]+1);
        }
    };
    dfs(root);
    return height;
}

vector<int> get_depth(int root=0,vector<vector<int>> &adj){
    vector<int>depth(n,0)
    function<void> dfs=[&](int node,int par=-1){
        for(auto &neigh:adj[node]){
            if(neigh==par)continue;
            depth[child]=depth[node]+1;
            dfs(child,node);
        }
    };
    dfs(root);
    return depth;
}

int get_diameter(vector<vector<int>>&adj){
    int random=0;
    vector<int>depth;
    depth=get_depth(random,adj);
    int max_depth=-1,end_node=-1;
    for(int i=0;i<n;++i){
        if(depth[i]>max_depth){
            max_depth=depth[i];
            end_node=i;
        }
    }
    depth=get_depth(end_node,adj);
    int diameter=-1;
    for(auto &x)diameter=max(diameter,x);
    return diameter
}
