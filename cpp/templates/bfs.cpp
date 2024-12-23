#include "bits/stdc++.h"
using namespace std;

void bfs(){
    vector<vector<int>> adj;
    int n,s;//s-source
    queue<int>q;
    vector<bool>visited(n);
    vector<int>d(n),p(n);//d-dist,p-parent for path reconstruction
    q.push(s);
    visited[s]=true;
    p[s]=-1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int neigh:adj[node]){
            if(!visited[neigh]){
                visited[neigh]=true;
                q.push(neigh);
                d[neigh]=d[node]+1;
                p[neigh]=node;
            }
        }
    }=
}

int main(){
    bfs();
    return 0;
}