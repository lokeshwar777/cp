#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> adj;

#define INF 1e15
int dist[n][n], adj[n][n];
void initialise(int n){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i==j)dist[i][j]=0;
            else if(adj[i][j]!=INF)dist[i][j]=adj[i][j];
            else dist[i][j]=INF;
        }
    }
}

void floyd_warshall(int n){
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    void dijkstra(n); // O(n^3)
    return 0;
}