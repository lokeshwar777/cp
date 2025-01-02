#include "bits/stdc++.h"
#define ll long long
#define sortv(vec) sort(vec.begin(),vec.end())
#define setll set<ll>
#define setpll set<pair<ll,ll>>
#define search(s,x) s.find(x)!=s.end()
#define fori(x,n) for(ll i=x;i<n;++i)
#define forr(n,x) for(ll i=n;i>=x;--i)
#define forx(x,vec) for(auto &x:vec)
#define vec1d(vec,n) vector<ll> vec(n)
#define vec1dx(vec,n,x) vector<ll> vec(n,x)
#define vec2d(vec,n,m) vector<vector<ll>> vec(n,vector<ll>(m))
#define vec2dx(vec,n,m,x) vector<vector<ll>> vec(n,vector<ll>(m,x))
#define vec3d(vec,n,m,k) vector<vector<vector<ll>>> vec(n,vector<vector<ll>>(m,vector<ll>(k)))
#define vec3dx(vec,n,m,k,x) vector<vector<vector<ll>>> vec(n,vector<vector<ll>>(m,vector<ll>(k,x)))
using namespace std;

// function<(ll,ll)> f=[&](ll i,ll j){
//     if(i==n-1&&j==n-1)return 0;

// };

int main(){
    ll n,m,k;cin>>n>>m>>k;
    vec2d(vec,n,m);vec2dx(dp,n,m,-1);
    forx(x,vec)forx(y,x)cin>>y;
    // forx(x,vec){forx(y,x)cout<<y<<" ";cout<<endl;}
}
