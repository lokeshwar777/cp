#include "bits/stdc++.h"
#define ll long long

using namespace std;

ll n,t,k,res,inf=1e15;

int main(){
	cin>>t;
	while (t--) {
        cin>>n>>k;
        vector<ll>a(n),b(n);
        for(ll i=0;i<n;++i)cin>>a[i];
        for(ll i=0;i<n;++i)cin>>b[i];
        vector<pair<ll,ll>> vec(n);
        for(ll i=0;i<n;++i)vec[i]={b[i],a[i]};
        sort(vec.begin(),vec.end(),[](auto &p1,auto &p2){
            if(p1.first==p2.first)return p1.second>p2.second;
            return p1.first>p2.first;
        });
        vector<vector<vector<vector<ll>>>> dp(n,vector<vector<vector<ll>>>(k+1,vector<vector<ll>>(n+1,vector<ll>(2,-1))));
        function<ll(ll,ll,ll,ll)> solve=[&](ll i,ll rem,ll mi,ll t){
            if(i==n)return (rem>=0)?1ll*0:-(inf);
            if(dp[i][rem][mi][t]!=-1)return dp[i][rem][mi][t];
            ll nb=solve(i+1,rem,mi,t),x=0ll,y=0ll,mv=0;
            if(mi!=n)mv=(t==0)?vec[mi].first:vec[mi].second;
            if(mv<=vec[i].first)x=vec[i].first+solve(i+1,rem,mi);
            
            // if(mi==n||a[mi]<=a[i])solve(i+1,rem,);
        //     ll y=solve(i+1,rem);
            // return dp[i][rem][mi]=max(l,max(x,y));
            return 1ll;
        };
        res=solve(0,k,n,0);
        // cout<<res<<endl;
        // cout<<(res?"YES":"NO")<<endl;
	}
    return 0;
}