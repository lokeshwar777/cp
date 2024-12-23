#include "bits/stdc++.h"
using namespace std;

int main(){
    string a,b;cin>>a>>b;
    int n=a.size(),m=b.size();
    
    // vector<vector<int>> memo(n,vector<int>(m,-1));
    // function<int(int,int)> f=[&](int i,int j){
    //     if(i==n||j==m)return 0;
    //     if(memo[i][j]!=-1)return memo[i][j];
    //     if(a[i]==b[j])return memo[i][j]=1+f(i+1,j+1);
    //     return memo[i][j]=max(f(i+1,j),f(i,j+1));
    // };
    // int res=f(0,0);
    // cout<<res<<endl;

    // for(auto &x:memo){
    //     for(auto &y:x){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }

    // int i=0,j=0;
    // while(i<n&&j<m){
    //     if(a[i]==b[j]){
    //         cout<<a[i];
    //         i++;j++;
    //     }else{
    //         if(i+1<n&&memo[i+1][j]==memo[i][j])i++;
    //         else j++;
    //     }
    // }

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=n-1;i>=0;--i)for(int j=m-1;j>=0;--j)
    dp[i][j]=(a[i]==b[j])?(1+dp[i+1][j+1]):max(dp[i+1][j],dp[i][j+1]);

    for(auto &x:dp){
        for(auto &y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

    int i=0,j=0;
    while(i<n&&j<m){
        if(a[i]==b[j]){
            cout<<a[i];
            i++;j++;
        }else{
            if(i+1<n&&dp[i+1][j]==dp[i][j])i++;
            else j++;
        }
    }

    return 0;
}