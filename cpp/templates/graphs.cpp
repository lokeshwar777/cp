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

/*****************************************************************************/

// luv's template
void dfs(int vertex){
    /** take action on the vertex after
     *  entering the vertex
     **/
    vis[vertex]=true;
    for(auto child:graph[vertex]){
        if(vis[child])continue;
        /** take action on the child before
         *  entering the child node
         **/ 
        dfs(child);
        /** take action on the child after
         *  exiting the child node
         **/ 
    }
    /** take action on the vertex before
     *  exiting the vertex
     **/ 
}

/*****************************************************************************/

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

/*****************************************************************************/

// weighted
vector<vector<pair<int,int>>> adj;
for(auto vec:edges){
    int u=vec[0],v=vec[1],cost=vec[2];
    adj[u].push_back({v,cost});
    adj[v].push_back({u,cost});
}

/*****************************************************************************/

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

/*****************************************************************************/

struct edge{
    int from;
    int to;
    int weight;
}

vector<edge> EDGES;

void bellman_ford(int source,int n){
    dist[source]=0;
    while(--n){
        for(auto E:EDGES){
            int parent=E.from;
            int child=E.to;
            int weight=E.weight;
            if(dist[parent]==inf)continue; // can't reach parent
            if(dist[child]<=dist[parent]+weight)continue;
            dist[child]=dist[parent]+weight;
        }
    }
}

// taking input for directed graphs
int n,m;
cin>>n>>m;
for(int i=0;i<m;++i){
    int parent,child,weight;
    cin>>parent>>child>>weight;
    struct edge E;
    E.from=parent;
    E.to=child;
    E.weight=weight;
    EDGES.push_back(E);
}

// taking input for undirected graphs
int n,m;
cin>>n>>m;
for(int i=0;i<m;++i){
    int parent,child,weight;
    cin>>parent>>child>>weight;
    struct edge E1,E2;
    E1.from=parent;
    E1.to=child;
    E1.weight=weight;
    EDGES.push_back(E1);
    E2.from=child;
    E2.to=parent;
    E2.weight=weight;
    EDGES.push_back(E2);
}

int source=0;
void bellman_ford(source,n); // O(n*m)
    
/*****************************************************************************/

// edge-pair<int,pair<int,int>>-(weight,(u,v))
int kruskals_mst(vector<pair<int,pair<int,int>>> edges,int n){
    sort(edges.begin(),edges.end());
    int total=0;
    for(auto [weight,edge]:edges){
        if(find_set(edge.first)==find_set(edge.second))continue;
        total+=weight;
        union_sets(edge.first,edge.second);
    }
    return total;
}

/*****************************************************************************/