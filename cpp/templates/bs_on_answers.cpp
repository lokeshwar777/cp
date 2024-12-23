#include <iostream>
using namespace std;
#define MAX_SIZE 100100

// using lli = long long;
#define int long long

int n,k;
int arr[MAX_SIZE];

int check(int mid) {
    int last_painter_time_left = 0;
    int no_of_painters_spawned =0;

    for (int i = 0 ;i < n ;i++) {
        if (last_painter_time_left >= arr[i]) {
            last_painter_time_left-= arr[i];
        }else{
            no_of_painters_spawned++;
            if (no_of_painters_spawned>k)return 0;
            last_painter_time_left = mid;
            if(last_painter_time_left>=arr[i]) last_painter_time_left -= arr[i];
            else return 0;
        }
    }
    return 1;
}

signed main() {
    cin>>n>>k;
    int sum = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }

    int lo=0,hi=sum,ans=1;
    while (lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(check(mid)==1){
            ans=mid;
            hi=mid-1;
        } else{
            lo=mid+1;
        }
    }
    cout<<endl;
    return 0;
}