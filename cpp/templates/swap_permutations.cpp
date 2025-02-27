#include "bits/stdc++.h"
using namespace std;

unordered_set<string>seen;

def generate_exact_swaps(string s,int swaps_left){
    if(swaps_left==0){
        seen.add(''.join(l));
        return;
    }
    seen.insert(s);
    int n=s.size();
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            swap(s[i],s[j]);
            generate_exact_swaps(l,swaps_left-1)
            swap(s[i],s[j]);
        }
    }
}

void generate_atmost_swaps(string s,int swaps_left,int start_index){
    if(swaps_left<0)return;
    seen.insert(s);
    int n=s.size();
    for(int i=start_index;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(s[i]==s[j])continue;
            swap(s[i],s[j]);
            generate_atmost_swaps(s,swaps_left-1,i+1);
            swap(s[i],s[j]);
        }
    }
}