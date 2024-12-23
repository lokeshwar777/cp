#include <bits/stdc++.h>
using namespace std;

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

int main() {
    return 0;
}