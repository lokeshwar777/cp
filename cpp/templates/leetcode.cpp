using ll=long long;
const ll MOD=1e9+7;
// const N=1e5;
ll pow(ll  base,ll exp,ll MOD){ll ans=1;while(exp>0){if(exp&1)ans=(ans*base)%MOD;base=(base*base)%MOD;exp>>=1;}return ans;}
ll inv(ll x){return pow(x,MOD-2,MOD);}
ll add(ll a,ll b){return ((a%MOD)+(b%MOD))%MOD;}
ll sub(ll a,ll b){return ((a%MOD)-(b%MOD)+MOD)%MOD;}
ll mul(ll a,ll b){return ((a%MOD)*(b%MOD))%MOD;}
ll divmod(ll a,ll b){return mul(a,inv(b));}
vector<ll> get_fact(ll n){vector<ll>fact(n+1,1);for(ll i=1;i<=n;++i)fact[i]=(fact[i-1]*1LL*i)%MOD;return fact;}
vector<ll>fact=get_fact(N);
ll get_comb(ll n,ll r){if(r>n||n<0||r<0)return 0;return divmod(fact[n],mul(fact[r],fact[n-r]));} // choose exactly r out of n
// vector<bool> get_prime_sieve(ll n){vector<bool>isPrime(n,true);isPrime[0]=isPrime[1]=false;for(int i=2;i*i<=n;++i){if(!isPrime[i])continue;for(int j=i*i;j<=n;j+=i){isPrime[j]=false;}}return isPrime;} // O(loglogn)

#define all(x) x.begin(),x.end()
#define rep(x,vec) for(auto &x:vec)
template<typename T>void print(const T& vec){for(auto &x:vec)cout<<x<<" ";cout<<endl;}


class Solution {
public: