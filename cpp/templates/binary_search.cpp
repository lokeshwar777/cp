// # include <bits/stdc++.h>
# include <iostream>

using namespace std;

int n;
int arr[100001];
int x;

int check(int mid) {
    if(arr[mid]>=x) return 1;
    return 0;
}

int main() {
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    cin>>x;

    // lower bound
    int lo=0;
    int hi=n-1;
    int ans=n; // default

    while(lo<=hi) {
        int mid=lo+(hi-lo)/2;
        if(check(mid)==1) {
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    cout << "lower bound is " << ans << endl;

    return 0;
}