#include "bits/stdc++.h"
using namespace std;

int n;

int inclusion_exclusion(vector<int> vec,int limit){
    int count=0;
    for(int mask=1;mask<(1<<n);++mask){
        int set_bits = __builtin_popcount(mask), comb_lcm=1;
        for(int i=0;i<n;++i){
            if(((1<<i)&mask) != 0){ // checking if the element is part of the combination
                comb_lcm = lcm(comb_lcm,vec[i]);
            }
        }
        if(set_bits&1) count+=limit/comb_lcm;
        else count-=limit/comb_lcm;
    }
    return count;
}

int main() {
    cin>>n;
    vector<int> vec(n);
    for(auto &x:vec)cin>>x;
    int limit;cin>>limit;
    int res = inclusion_exclusion(vec,limit);
    cout<<res;
}