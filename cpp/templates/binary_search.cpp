// # include <bits/stdc++.h>
# include <iostream>

using namespace std;

int n;
int arr[100001];
int x;

int lowerBound(vector<int> &nums, int target){
    int low = 0, high = n - 1, ans = -1;
    while (low <= high){
        int mid = ((high - low) >> 1) + low;
        // cout << mid << " " << nums[mid] << endl;
        if (nums[mid] == target)
            ans = mid;
        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return ans;
}

int upperBound(vector<int> &nums, int target){
    int low = 0, high = n - 1, ans = -1;
    while (low <= high){
        int mid = ((high - low) >> 1) + low;
        if (nums[mid] == target)
            ans = mid;
        if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return ans;
}

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