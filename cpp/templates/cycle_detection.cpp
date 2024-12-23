#include "bits/stdc++.h"
using namespace std;

// undirected graph
bool has_cycle=false;
void dfs(int node,int parent){
    visited[node]=true;
    for(int neigh:adj[node]){
        if(neigh==parent)continue;
        if(visited[neigh])has_cycle=true;
        else dfs(neigh,node);
    }
}

// directed graph
bool in_stack[n]={false};
bool has_cycle=false;
void dfs(int node){
    visited[node]=true;in_stack[node]=true;
    for(int neigh:adj[node]){
        if(visited[neigh])if(in_stack[neigh])has_cycle=true;
        else dfs(neigh);
    }
    in_stack[node]=false;
}

int main(){
    return 0;
}