#include "bits/stdc++.h"
using namespace std;

#define int long long
#define ll long long
const int MOD=1e9+7;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;cin>>s;
    
    int mod;cin>>mod;
    int n=s.size();

    vector<vector<vector<int>>> dp(n,vector<vector<int>>(mod,vector<int>(2,-1)));
    function<int(int,int,int)> solve=[&](int index,int currmod,int istight){
        // cout<<index<<" "<<n<<endl;
        if(index==n)return 1ll*(currmod==0);
        if(dp[index][currmod][istight]!=-1)return dp[index][currmod][istight];
        int ans=0;
        for(int digit=0;digit<=(istight?(s[index]-'0'):9);++digit){
            ans=(ans+solve(index+1,(currmod+digit)%mod,istight&&(digit==(s[index]-'0')))%MOD)%MOD;
        }
        return dp[index][currmod][istight]=ans;
    };
    int res=(solve(0,0,1)-1+MOD)%MOD;
    cout<<res;
    return 0;
}