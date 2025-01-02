#include "bits/stdc++.h"
using namespace std;

// type aliases
using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;
using viii = vector<vector<vector<int>>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vvvll = vector<vector<vector<ll>>>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll,ll>;
using mii = map<int, int>;
using mll = map<ll,ll>;

// constants
const int MOD = 1e9 + 7;
const int INF = INT_MAX;

// fast io
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

// macros
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define min_pq(x) priority_queue<x,vector<x>,greater<x>>
#define max_pq(x) priority_queue<x>
#define max(vec) *max_element(vec.begin(),vec.end())
#define min(vec) *min_element(vec.begin(),vec.end())

// debugging
#ifdef DEBUG
#define dbg(x) cerr << #x << " = " << (x) << endl;

#else
#define dbg(x)
#endif



int n,t,a,b,c,l,h,k,w,x,y,m,f,ans,res;

int solve(){
	ans=0;
}

int main(){
	cin>>t;
	while(t--){


	}
	res=solve();
	cout<<res<<endl;
	cout<<(res>=1)?"YES":"NO"<<endl;	
	return 0;
}