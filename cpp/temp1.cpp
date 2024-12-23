#include "bits/stdc++.h"

using namespace std;

int n,t,k,m;

int main(){
	cin>>t;
	while (t--) {
        cin>>n;
        // string s;cin>>s;
        // vector<int>vec(n);
        // for(int i=0;i<n;++i){
        //     cin>>vec[i];
        // }
        vector<int> vec(n,0);
        function<int()> solve=[&](){
            
            return 1;
        };
        int res=solve();
        // cout<<s<<endl;
        // for(auto &y:vec)cout<<y;
        // cout<<endl<<endl;
        cout<<(res?"YES":"NO")<<endl;
	}
    return 0;
}