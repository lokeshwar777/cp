// Disjoint set union
#include "bits/stdc++.h"
using namespace std;

const int N = 1e5;

int parent[N],sz[N];

// naive - TC=SC=O(n)
int find_set(int n){ 
    if(parent[n]==n)return n;
    return find_set(parent[n]);
}

// SC=O(n), TC= (O(n) for find_set) + (O(n) for union_set)
int union_sets(int a,int b){ 
    a=find_set(a);b=find_set(b);
    if(a!=b)parent[b]=a;
    return a;
}

// with path compression - TC=O(logn)
int find_set(int n){ 
    if(parent[n]==n)return n;
    return parent[n]=find_set(parent[n]);
}

// union by size(small to large) - TC=O(logn)
int sz[MAX_NODES];
void union_sets(int a,int b){ // or merge
    a=find_set(a);b=find_set(b);
    if(sz[a]>sz[b])swap(a,b);// make the a smaller and b larget if not already
    parent[a]=b;
    sz[b]+=sz[a];
}

// Optimisation - path compression + union by size = O(α(n))

int main(){
    for(int i=0;i<N;++i){parent[i]=i;sz[i]=1;}
    return 0;
}