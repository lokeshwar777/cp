#include "bits/stdc++.h"
#define int long long
using namespace std;

int n,maxi;
int freq[100001],dp[100001];

int solve(int i){
    if(i>maxi)return 0ll;
    if(dp[i]!=-1)return dp[i];
    dp[i]=max(solve(i+1),(i*freq[i])+solve(i+2));
    return dp[i];
}

signed main(){
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;++i){
        cin>>vec[i];
        maxi=max(maxi,vec[i]);
        freq[vec[i]]++;
    }
    int mini=*min_element(vec.begin(),vec.end());
    memset(dp,-1,sizeof(dp));
    int res=solve(mini);
    cout<<res<<endl;
    return 0;
}