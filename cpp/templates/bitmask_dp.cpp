#include "bits/stdc++.h"
// #define int long long
using namespace std;

const int MOD=1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vector<vector<int>> vec(n,vector<int>(n));
    vector<int> dp((1<<n),-1);
    for(auto &x:vec){for(auto &y:x){cin>>y;}}
    function<int(int)> solve=[&](int mask){
        int index=__builtin_popcount(mask),ans=0;
        // if(mask==((1<<n)-1))return 1; or
        if(index==n)return 1;
        if(dp[mask]!=-1)return dp[mask];
        for(int i=0;i<n;++i){
            if(!(mask&(1<<i))&&vec[index][i]){
                ans=(ans+solve(mask|(1<<i)))%MOD;
            }
        }
        return dp[mask]=ans;
    };
    int res=solve(0);
    cout<<res;
}