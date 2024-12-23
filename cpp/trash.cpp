#include "bits/stdc++.h"

using namespace std;
// atcoder
// int n,t,k,m;
    // cin>>n;
    // vector<int>vec(n);
    // for(int i=0;i<n;++i){
    //     cin>>vec[i];
    // }
int f(char c){
    if(c=='R')return 0;
    if(c=='D')return 1;
    if(c=='L')return 2;
    if(c=='U')return 3;
    return -1;
}

int main(){
    int r,c,sx,sy;cin>>r>>c>>sx>>sy;
    vector<vector<char>> vec(r,vector<char>(c));
    vector<vector<bool>> vis(r,vector<bool>(c,false));
    for(auto &x:vec)for(auto &y:x)cin>>y;
    string s;cin>>s;
    int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
    function<void()> solve=[&](){
        int h=0,i=sx-1,j=sy-1;
        if(vec[i][j]=='@'){h++;vis[i][j]=true;}
        for(const char &c:s){
            // cout<<i<<" "<<j<<endl;
            int ii=i+dx[f(c)],jj=j+dy[f(c)];
            if(ii>0&&ii<r-1&&jj>0&&jj<c-1&&vec[ii][jj]!='#'){
                i=ii;j=jj;
                if(vec[i][j]=='@'&&!vis[i][j]){h++;vis[i][j]=true;}
            }
        }
        cout<<i+1<<" "<<j+1<<" "<<h;
    };
    solve();
    // cout<<res<<endl;
    // cout<<s<<endl;
    // for(auto &y:vec)cout<<y;
    // cout<<endl<<endl;
    // cout<<(res?"YES":"NO")<<endl;

    return 0;
}

#include "bits/stdc++.h"
#define ll long long

using namespace std;
// cf
ll n,t,k,m,x,y,sum,lo,hi,l,r;

int main(){
	cin>>t;
	while (t--) {
        cin>>n>>k;m=0;
        vector<ll>a(n),b(n);
        for(ll i=0;i<n;++i)cin>>a[i];
        for(ll i=0;i<n;++i){cin>>b[i];m=max(m,b[i]);}
        vector<pair<int,int>> vec(n);
        for(ll i=0;i<n;++i)vec[i]={b[i],a[i]};
        sort(vec.begin(),vec.end(),[](auto &p1,auto &p2){
            if(p1.first==p2.first)return p1.second>p2.second;
            return p1.first>p2.first;
        });
        function<ll()> solve=[&](){
            ll x=m;
            for(auto &p:vec){
                x=min(int(x),((k>0)?p.first:p.second));
                if(k>0)k--;
                cout<<p.first<<','<<p.second<<" "<<k<<" "<<x<<endl;
            }
            return x;
        };
        // for(auto &q:vec)cout<<q.first<<','<<q.second<<" ";
        // cout<<endl;
        ll res=solve();
        cout<<res<<endl;
        // cout<<(res?"YES":"NO")<<endl;
	}
    return 0;
}


#include "bits/stdc++.h"
#define ll long long

using namespace std;
// cf
ll n,t,k,m,x,y,sum,lo,hi,l,r,res;

int main(){
	cin>>t;
	while (t--) {
        cin>>n>>k;
        vector<ll>a(n),b(n);
        for(ll i=0;i<n;++i)cin>>a[i];
        for(ll i=0;i<n;++i)cin>>b[i];
        function<bool(ll)> solve=[&](ll v){
            ll rem=k;
            for(ll i=0;i<n;++i){
                if(v<=a[i])continue;
                rem--;
            }
            return rem>=0;
        };
        res=lo=*min_element(a.begin(),a.end());hi=*min_element(b.begin(),b.end());
        while(lo<=hi){
            m=lo+(hi-lo)/2;
            if(solve(m)){
                res=m;lo=m+1;
            }else hi=m-1;
        }
        cout<<res*n<<endl;
        // cout<<(res?"YES":"NO")<<endl;
	}
    return 0;
}