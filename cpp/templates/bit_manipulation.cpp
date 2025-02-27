#include "bits/stdc++.h"
using namespace std;
using ll = long long;

// no. of set bits in - __builtin_popcount(x) or popcount(static_cast<unsigned int>(x))
// rightmost setbit - `~(x-1)&x` <=> `-x&x`


unsigned int get_leftmost_set_bit(unsigned int x,int num_bits=32){
    if(x==0)return 0;
    for(int shift=1;shift<=num_bits/2;shift<<=1)x|=x>>shift;
    // for(int shift=1;shift<num_bits;shift<<=1)x|=x>>shift; // not accurate
    return x-(x>>1);
}

ll get_rightmost_set_bit(ll x){return -x&x;}
ll get_leftmost_set_bit(ll x,ll num_bits=32){
    if(x==0)return 0;
    for(int shift=1;shift<=num_bits/2;shift<<=1)x|=x>>shift;
    return x-(x>>1);
}


ll kAndSumSubarr(vector<int>&vec,int k=1){
    ll n=vec.size();
    map<ll,ll>prev_ends,all_and_freq;
    // for(ll curr_ind=0;curr_ind<n;++curr_ind){ // this can also be taken, but why to complicate
    for(ll curr_ind=n-1;curr_ind>=0;--curr_ind){
        ll curr_val=vec[curr_ind];
        map<ll,ll>new_ends;
        // we have '& value' of `prev_val` till `prev_ind`
        for(auto &[prev_val,prev_ind]:prev_ends){
            ll new_val=prev_val&curr_val;
            new_ends[new_val]=max(new_ends[new_val],prev_ind); // why max?, if the new value already exists
        }
        new_ends[curr_val]=max(new_ends[curr_val],curr_ind); // do not forget to include the current value (again max)
        prev_ends=new_ends;

        // printing map values
        // cout<<"At Index "<<curr_ind<<endl;
        // for(auto &[val,last_ind]:new_ends){
        //     cout<<"Val: "<<val<<", ends at index: "<<last_ind<<endl;
        // }
        // cout<<endl;

        ll l=curr_ind;
        // cout<<"Starting at index : "<<curr_ind<<endl;
        for(auto it=new_ends.rbegin();it!=new_ends.rend();++it){
            ll r=it->second,val=it->first;
            // cout<<"We get "<<val<<" if end is in ["<<l<<","<<r<<"]"<<endl;
            all_and_freq[val]+=r-l+1;
            l=r+1;
        }
    }
    // for(auto &[val,freq]:all_and_freq){
    //     cout<<"Val: "<<val<<" Freq: "<<freq<<endl;
    // }
    return all_and_freq[k];
}


int main(){
    // unsigned int n;cin>>n;
    // unsigned int leftmost_setbit=get_leftmost_set_bit(n);
    int n;cin>>n;
    vector<int>vec(n);
    for(auto &x:vec)cin>>x;
    ll cnt=kAndSumSubarr(vec);
    cout<<cnt;
}
