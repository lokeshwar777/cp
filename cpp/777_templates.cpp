#include "bits/stdc++.h"
using namespace std;
using lli=long long;
#define endl '\n'

/*********************************** DP ***************************************/

/*
// 1. Maximum Sum of All Subarrays (Kadane's algo)
// default ans - 0 if empty subarrays are allowed, -inf for max
int maxKadane(vector<int>dp,int ans){
	int n=dp.size();
	// dp[i] -> max subarray sum ending at i
	for(int i=0;i<n;++i){
		if(i)dp[i]=max(dp[i],dp[i-1]+dp[i]);
		ans=max(ans,dp[i]);
	}
	return ans;
}
*/


/*********************************** PREFIX SUM *******************************/

/*
// 1. Prefix sum + no. of subarrays with sum `x`
vector<lli> vec,prefix;

void solve(){
	int n;cin>>n;
	vec.resize(n);
	prefix.resize(n);
	for(int i=0;i<n;++i){
		cin>>vec[i];
		prefix[i]=vec[i];
		if(i)prefix[i]+=prefix[i-1];
	}
	lli sum;cin>>sum;
	lli cnt=0;
	map<int,int>mp;
	mp[0]=1;
	for(int j=0;j<n;++j){
		cnt+=mp[prefix[j]-sum];
		mp[prefix[j]]++;
	}
	cout<<cnt<<endl;
}
*/

multiset<pair<lli,lli>> mt;
 
void insert(lli l,lli r){
	auto li=mt.lower_bound();
}

int getSegCnt(){
	return mt.size();
}

void solve(){
	int q;cin>>q;
	while(q--){
		char ch;cin>>ch;
		if(ch=='+'){
			lli l,r;
			cin>>l>>r;
		}else{

		}
	}
}


/*********************************** KMP ************************************/

/*
// vivek gupta's version
vector<int> kmp(stirng s){
	vector<int>lps;lps[0]=-1;
	int i=0,j=-1;
	while(i<n){
		while(j!=-1&&s[i]!=s[j])j=lps[j];
		i++;j++;lps[i]=j;
	}
	return lps;
}
*/

/******************** MONOTONIC (STACKS & QUEUES) *****************************/

/* 
// vivek gupta's version
vector<int> get_nextgr(vector<int>&vec){
    int n=vec.size();
    vector<int>nextgr(n,0);
    for(int i=n-1;i>=0;--i){
        int ans=i+1;
        while(ans<n&&vec[ans]<=vec[i])ans=nextgr[ans];
        nextgr[i]=ans;
    }
    return nextgr;
}
*/


/*********************************** TREES ************************************/

/* 
// 1. Diameter of an undirected tree
vector<vector<pair<int,int>>> g;

vector<int> dis;

void dfs(int nn,int pp,int dd){
	dis[nn]=dd;
	for(auto v:g[nn]){
		if(v.first!=pp){
			dfs(v.first,nn,dd+v.second);
		}
	}
}

void solve(){
	int n;cin>>n;
	g.resize(n+1);
	dis.resize(n+1);
	for(int i=0;i<n-1;++i){
		int a,b,wt=1;
		cin>>a>>b;
		// cin>>wt;
		g[a].emplace_back(b,wt);
		g[b].emplace_back(a,wt);
	}
	dfs(1,0,0);
	int mx=1;
	for(int i=2;i<n;++i){
		if(dis[mx]<dis[i])mx=i;
	}

	dfs(mx,0,0);
	mx=1;
	for(int i=2;i<n;++i){
		if(dis[mx]<dis[i])mx=i;
	}

	cout<<dis[mx]<<endl;
}
*/


/*
// 2. Center(s) of an undirected tree
vector<vector<pair<int,int>>> g;

vector<int> dis; vector<int> par;

void dfs(int nn,int pp,int dd){
	dis[nn]=dd;
	par[nn]=pp;
	for(auto v:g[nn]){
		if(v.first!=pp){
			dfs(v.first,nn,dd+v.second);
		}
	}
}

void solve(){
	int n;cin>>n;
	g.resize(n+1);
	dis.resize(n+1);
	par.resize(n+1);
	for(int i=0;i<n-1;++i){
		int a,b,wt=1;
		cin>>a>>b;
		// cin>>wt;
		g[a].emplace_back(b,wt);
		g[b].emplace_back(a,wt);
	}
	dfs(1,0,0);
	int mx=1;
	for(int i=2;i<n;++i){
		if(dis[mx]<dis[i])mx=i;
	}

	dfs(mx,0,0);
	mx=1;
	for(int i=2;i<n;++i){
		if(dis[mx]<dis[i])mx=i;
	}

	vector<int> path;
	int temp=mx;
	while(temp!=0){
		path.push_back(temp);
		temp=par[temp];
	}

	// cout<<dis[mx]<<endl;
	cout<<(path.size()-1)<<endl;

	// center
	if(path.size()%2){
		int center=path[path.size()/2];
	}else{
		int center1=path[path.size()/2];
		int center2=path[(path.size()-1)/2];
	}
}
*/


/*
// 2. Centroid of an undirected tree
*/

/******************************************************************************/

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// int _t;cin>>_t;while(_t--)
	solve();
}