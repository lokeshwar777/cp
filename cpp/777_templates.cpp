#include "bits/stdc++.h"
using namespace std;
using lli=long long;
#define endl '\n'

/********************************* RECURSION **********************************/
/** LCCM
 * 1. Level
 * 2. Choice
 * 3. Check
 * 4. Move
 */

/*
int n;
int rec(int level){
    // pruning
    if(level>n){
        return 0; // invalid
    }

    // base case
    if(level==n){ // for most of the counting problems we generally return 0 or 1
        return 1;
    }

    // cache check

    int ans=0;
    // transitions
    // loop over choices

    // save and return
    return ans;
}

void printsol(int level,int param){
    if(level==n)return;
    if(rec(level+1,param)==1){ // not take
        printsol(level+1,param);
    }else if(rec(level+1,param-vec[level])){ // take
        cout<<vec[level]<<endl;
        printsol(level+1,param-vec[level]);
    }
}

*/

/*********************************** DP ***************************************/
// always store rec(level,something_left) in case of queries for caching
// separate boolean array (done) to cache double values or if -1 is a potential return value
// always use recurrence to get values instead of dp array (precaution)
// initial values - 0(counting),inf(minimisation),-inf(maximisation)
// use offset for -ve index values while caching
// don't use INT_MIN and INT_MAX instead use 1e9 or 1e18
// infinite supply
// brute - put all constraints into states
// we can also all extra check for -ve values intead of offset or explicitly check for some conditions (like in atcode DP C)
// average no. of transitions - O(V + E)
// cout << setprecision(9) << fixed << doubleValue;
// game DP - just define 1 config, rest taken care automatically

/* Forms
1 - pick, not pick - knapsack
2 - ending form - prev, streak - LIS,grid - dependencies (path, sequence, subarray)
3 - multiple sequences + match - LCSubsequence
4 - LR, interval - rod cutting, MCM, palindromic - (atcoder slimes)
5 - game - (states=config) - periodic function, combinatorial
*/

/* Bitmask DP
1. Matching based - 
2. Graph nodes/cycles - 
3. Pairing values - 
4. Breaking groups - 
5. Profile DP - 
6. Submask decomposition - 
*/

/* Digit DP

*/

/* String DP

*/

/* Tree DP
- atcoder DP P

*/

/* DP on Probability
- self-referential transitions (atCoder DP Sushi)
- Markov Decision Process (MDP)
*/

/* Ideas for substring or subsequence match
- prefix match
- building automata using KMP (finite state machine for transitions)
- mask for config
*/

/* Steps
1. Form detection
2. State design
3. Transition design
4. TL Check
5. Order of computation
*/

/* Code

int rec(int level) {
    // pruning
    // base case
    // cache check
    // transitions or compute
    // save and return
}

*/


/* iterative coding
- order of computation + base case + tricks 
- use if all states are visited
- LR DP - row wise(L decreases, R increases) or diagonal wise(length increases, L increases), length = r-l+1
- 
*/

/* Optimisations
1. State Space Reduction 
    - eliminate states or use a DS to get min or sum in less TC
    - using j&1 in iterative coding changes TC from O(k*n) to O(2*n)
2. State Rotation
	- switch between what you store and what you return (atcoder DP E)
3. Transition Optimisation
	- O(k*n) to O(n) using DS like monotonic deque, prefix caching (atcoder candies)
4. 
*/

/* LCSubsequence
int topDown(int i,int j) {
    if (i == n1 || j == n2) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = (a[i] == b[j]) ? (1 + topDown(i + 1, j + 1)) : max(topDown(i + 1, j), topDown(i, j + 1));
}

void printLCS(int i, int j) {
    if (i == n1 || j == n2) return;
    if (topDown(i, j) == topDown(i + 1, j)) {
        printLCS(i + 1, j);
    } else if (topDown(i, j) == topDown(i, j + 1)) {
        printLCS(i, j + 1);
    } else {
        lcs += a[i];
        printLCS(i + 1, j + 1);
    }
}
*/

/*
// 1. Maximum Sum of All Subarrays (Kadane's algo) - https://youtu.be/gdyoAV-eTLk?si=_dJj-k_eCXrUOVPf
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

// par instead of vis
// think bottom up and use sections

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

/*********************************** GRAPHS ************************************/

// if uv is a back edge, then v is an ancestor of u

// DFS tree
// Connected Component - 
// Strongly Connected Component (SCC) - 2DFS and reverse graph - directed graph
// Bridges in a graph - edges which break a component into 2
// Cutpoints - vertices
// Bridge Tree - articulation, bi-directional components (BCC), connecting edges of diameter

/*
1. DFS
2. BFS - shortest path with equal weights
3. Connected Components - 1 -> N nodes, SCC
4. Path printing - backpointer, parent
5. Multi Source BFS - simultaneous
6. Cycles - undirected=parent+vis, directed=vis+path_vis, DFS or BFS
7. Coloring - bipartitie (odd=no, even=yes), DFS or BFS
8. Topological Sorting - DAG, DFS or BFS(Kahn's)
*/
// Complexities - O(V + E)

/*********************************** BINARY LIFTING ***************************/

// TC - O(nlogn) for precomputation, O(logn) for queries
// SC - O(nlogn)
// LCA



/******************************************************************************/

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// int _t;cin>>_t;while(_t--)
	solve();
}
