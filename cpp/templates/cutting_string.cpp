#include "bits/stdc++.h"
using namespace std;

int n,cuts;
string s,max_str="";

void divide_string(int i,int cuts_rem,vector<int> cuts_vec){
    if(cuts_rem==0){
        cuts_vec.push_back(n);
        int i=0;
        // for(auto cut:cuts_vec){cout<<s.substr(i,cut-i)<<" ";i=cut;}cout<<endl;
        for(auto cut:cuts_vec){
            cout<<s.substr(i,cut-i)<<" ";
            max_str=max(max_str,s.substr(i,cut-i));i=cut;
        }
        cout<<endl;
        return;
    }
    if(i==n)return;
    cuts_vec.push_back(i);
    divide_string(i+1,cuts_rem-1,cuts_vec);
    cuts_vec.pop_back(); // backtrack
    divide_string(i+1,cuts_rem,cuts_vec);
}

int main() {
    cin>>s>>cuts;n=s.size();
    vector<int>cuts_vec;
    divide_string(1,cuts-1,cuts_vec);
    cout<<"largest string is : "<<max_str;
}