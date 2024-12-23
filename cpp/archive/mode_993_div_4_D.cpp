#include "bits/stdc++.h"
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n),ans;
        for(int i=0;i<n;++i)cin>>vec[i];
        unordered_set<int> s;
        int k=1;
        for(const int x:vec){
            if(s.find(x)==s.end()){
                ans.push_back(x);
                s.insert(x);
            }else{
                while(s.find(k)!=s.end())k++;
                ans.push_back(k);
                s.insert(k);
            }
        }
        for(const int x:ans)cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}