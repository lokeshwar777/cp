#include "bits/stdc++.h"
using namespace std;

vector<int> vec; 

vector<int> z_func_trivial(string s){ // O(n^2)
    int n=s.size();
    vector<int> z(n,0);
    for(int i=1;i<n;++i){
        while(z[i]+i<n&&s[i+z[i]]==s[z[i]])z[i]++;
    }
    return z;
}

// z[i]-> how many characters starting at i matches the prefix
vector<int> z_func(string s){ // O(n) for string
// vector<int> z_func(vector<int> &s){ // O(n) for array
    int n=s.size();
    vector<int> z(n,0);
    for(int i=1,l=0,r=0;i<n;++i){
        if(i<r)z[i]=min(r-i,z[i-l]);
        while(z[i]+i<n&&s[i+z[i]]==s[z[i]])z[i]++;
        if(i+z[i]>r){
            l=i;
            r=i+z[i];
        }
    }
    return z;
}

vector<int> z_func_offset(vector<int>& s,int offset){
    int n=s.size()-offset;
    vector<int>z(n,0);
    for(int i=1,r=0,l=0;i<n;++i){
        if(i<r)z[i]=min(r-i,z[i-l]);
        while(z[i]+i<n&&s[z[i]+i+offset]==s[z[i]+offset])z[i]++;
        if(z[i]+i>r){
            l=i;
            r=z[i]+i;
        }
    }
    return z;
}

vector<int> kmp(string s){ // O(n)
    int n=s.size();
    vector<int> lps(n,0);
    for(int i=1;i<n;++i){
        int j=lps[i-1];
        while(j>0&&s[i]!=s[j])j=lps[j-1];
        lps[i]=j+(s[i]==s[j]);
    }
    return lps;
}

int main(){
    string s;cin>>s;
    string p;cin>>p;
    // vec=kmp(s);
    // vec=z_func(s);
    // vec=z_func_trivial(s);
    // vec=z_func_z_func_offset(s,0);
    for(auto &x:vec)cout<<x;cout<<endl;
}
