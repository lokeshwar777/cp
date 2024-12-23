#include "bits/stdc++.h"

using namespace std;
#define MAX_SIZE 1000000

// using lli = long long;
#define int long long

int n,k;
int arr[MAX_SIZE];

int check(int mid) {
    int products =0;

    for (int i = 0 ;i < n ;i++) {
        products += mid/arr[i];
        if (products>=k)return 1;
    }
    return 0;
}

signed main() {
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int lo=0,hi=arr[0]*k,ans=1;
    while (lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(check(mid)==1){
            ans=mid;
            hi=mid-1;
        } else{
            lo=mid+1;
        }
    }
    cout<<ans;
    cout<<endl;
    return 0;
}