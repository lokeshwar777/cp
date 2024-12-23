#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dijkstra(int source){
    dist[source]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,source});
    while(!pq.empty()){
        int node=pq.top().second;
        int weight=pq.top().first;
        pq.pop();
        if(visited[node])continue;
        visited[node]=true;
        for(auto neigh:adj[node]){
            if(visited[neigh])continue;
            if(dist[neigh]<dist[node]+weight)continue;
            dist[neigh]=dist[node]+weight;
            parent[neigh]=node; // reconstruction of the shortest path
            pq.push({dist[neigh],neigh});
        }
    }
}

int main(){
    int source=0;
    void dijkstra(source); // O(nlogn+m) ~O(n+m)
    return 0;
}