#include "bits/stdc++.h"
using namespace std;

int count_connected_components(){
    int ans=0;
    for(int i=0;i<n;++i){
        if(!vis[i]){
            dfs(i);
            ans++;
        }
    }
    return ans;
}
