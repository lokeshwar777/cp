#include "bits/stdc++.h"
using namespace std;


vector<vector<int>> adj;
bitset<100001> vis = 0;
vector<vector<int>> createAdjList(int& n, vector<vector<int>>& edges, bool is_directed = false) {
    vector<vector<int>> adjList(n);

    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        if (!is_directed) {
            adjList[v].push_back(u);
        }
    }

    return adjList;
}

int dfs(int node) {
    vis[node] = true;
    for (auto neigh : adj[node]) {
        if(vis[neigh])continue;
        dfs(neigh);
    }
    return 0;
}

int main(){
	int n = edges.size() + 1;	
    adj = createAdjList(n,edges);
    int res = 0;
    for (int i = 0 ; i < n ; ++i){
        if (!vis[i]) {
            res += dfs(i);
        }
    }
	return 0;
}


// weighted
vector<vector<pair<int,int>>> adj;
for(auto vec:edges){
    int u=vec[0],v=vec[1],cost=vec[2];
    adj[u].push_back({v,cost});
    adj[v].push_back({u,cost});
}

// dijkstra's using min pq and vis array
vector<int> res(n,-1),vis(n,0);
priority_queue<pii,vector<pii>, greater<pii>>pq; // cost till this node
pq.push({0,0});
while(!pq.empty()){
    auto p=pq.top();pq.pop();int cost=p.first,node=p.second;
    if(vis[node])continue;
    vis[node]=true;
    for(auto neighp:adj[node]){
        int neigh=neighp.first,weight=neighp.second;
        pq.push({cost+weight,neigh});
    }
}
return res;

