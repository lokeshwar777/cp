#include "bits/stdc++.h"
using namespace std;

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

int main(){
    // taking input for directed graphs
    // int n,m;
    // cin>>n>>m;
    // for(int i=0;i<m;++i){
    //     int parent,child,weight;
    //     cin>>parent>>child>>weight;
    //     struct edge E;
    //     E.from=parent;
    //     E.to=child;
    //     E.weight=weight;
    //     EDGES.push_back(E);
    // }

    // taking input for undirected graphs
    // int n,m;
    // cin>>n>>m;
    // for(int i=0;i<m;++i){
    //     int parent,child,weight;
    //     cin>>parent>>child>>weight;
    //     struct edge E1,E2;
    //     E1.from=parent;
    //     E1.to=child;
    //     E1.weight=weight;
    //     EDGES.push_back(E1);
    //     E2.from=child;
    //     E2.to=parent;
    //     E2.weight=weight;
    //     EDGES.push_back(E2);
    // }

    int source=0;
    void bellman_ford(source,n); // O(n*m)
    return 0;
}