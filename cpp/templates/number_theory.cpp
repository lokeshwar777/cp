#include "bits/stdc++.h"
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
using ll = long long;

const ll MOD=1e9+7;

ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}

// <------------------------------ EXPONENTIAION --------------------------------------->

ll bin_exp_recur(ll  base,ll exp) { // recursive binary exponentation
    if(exp==0)return 1;
    ll x=bin_exp_recur( base,exp/2);
    if(exp&1)return ( base*(1LL*x*x)%MOD)%MOD;
    return (1LL*x*x)%MOD;
}

// iterative binary exponentation
ll bin_exp_iter(ll  base,ll exp) { // log(exp)
    ll ans=1;
    while(exp>0){
        if(exp&1)ans=(ans*base)%MOD;
        base=(base*base)%MOD;
        exp>>=1;
    }
    return ans;
}

ll bin_exp_large() { // when mod is large i.e MOD > 1e9
    ll ans=1;
    while(exp>0){
        if(exp&1)ans=bin_multiply(ans,base)%MOD;
        base=bin_multiply(base,base)%MOD;
        exp>>=1;
    }
    return ans;
}

// for mulitplying large numbers
ll bin_multiply(ll  base,ll exp) { // log^2(n)
    ll ans=0;
    while(exp>0){
        if(exp&1)ans=(ans+base)%MOD;
        base=(base+base)%MOD;
        exp>>=1;
    }
    return ans;
}

// Euler's Totient Function (ETF) and Euler's Theorem
ll super_power(){

}

// <--------------------------------- DIVISORS ------------------------------------>

ll divisor_brute(ll n){ // O(n)
    ll sum=0,cnt=0;
    for(int i=1;i<=n;++i){
        if(n%i==0){
            cout<<i<<" "<<n/i<<endl;
            sum+=i;
            cnt++;
        }
    }
    // return sum;
    return cnt;
}

ll divisor_sum_cnt(ll n){ // O(sqrt(n))
    ll sum=0,cnt=0;
    for(int i=1;i*i<=n;++i){
        if(n%i==0){
            cout<<i<<" "<<n/i<<endl;
            sum+=i;
            cnt++;
            if(i!=n/i){
                sum+=n/i;
                cnt++;
            }
        }
    }
    // return sum;
    return cnt;
}

// prime factors - pi
/*
x=∑(pi^ni)=p1^n1+p2^n2+p3^n3+...+pm^nm
cnt=∏(ni+1)=(n1+1)*(n2+1)*(n3+1)*...*(nm+1)
sum=∏((pi^(ni+1))-1)/(pi-1)=((p1^(n1+1))-1)/(p1-1) * ((p2^(n2+1))-1)/(p2-1) * ... * ((pm^(nm+1))-1)/(pm-1)
*/


ll get_divisors(ll n){ // O(nlogn)
    vector<ll>divisors[n]; // creates an array of n vectors
    // vector<vector<ll>>divisors(n,vector<ll>()); // for dynamic use case
    for(int i=2;i<n;++i){
        for(int j=i;j<n;j+=i){
            divisors[j].push_back(i);
        }
    }
    return divisors;
}


// TODO : multiple count - lcm or something like that
void get_multiples(){

}

// <------------------------------- PRIME -------------------------------------->

vector<bool> get_prime_sieve(ll n){ // O(sqrtn*loglogn)
    vector<bool>isPrime(n,true);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<=n;++i){ // you can also use i*i<n
        if(!isPrime[i])continue;
        for(int j=2*i;j<=n;j+=i){ // you can also use i*i, O(loglogn), (logx = ∑(1/i) = ∫dx/x from 1 to n = 1/2+1/3+1/4+...)
            isPrime[j]=false;
        }
    }
    return isPrime;
}

// <-------------------------------- PRIME FACTORISATION ------------------------------------->

vector<ll> get_prime_factors(ll n){ // O(n)
    vector<ll> prime_factors;
    for(int i=2;i<=n;++i){
        while(n%i==0){
            prime_factors.push_back(i);
            n/=i;
        }
    }
    return prime_factors;
}

vector<ll> get_prime_factors(ll n){ // O(sqrt(n))
    vector<ll> prime_factors;
    for(int i=2;i*i<=n;++i){
        while(n%i==0){
            prime_factors.push_back(i);
            n/=i;
        }
    }
    if(n>1)prime_factors.push_back(n); // if only 1 prime factor is left
    return prime_factors;
}

vector<ll>highestPrime(n);
vector<ll>lowestPrime(n,-1);
vector<bool> get_prime_sieve(ll n){ // O(loglogn)
    vector<bool>isPrime(n,true);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<n;++i){ // you can also use i*i<n
        if(!isPrime[i])continue;
        highestPrime[i]=lowestPrime[i]=i;
        for(int j=2*i;j<n;j+=i){ // you can also use i*i, O(loglogn), (logx = ∑(1/i) = ∫dx/x from 1 to n = 1/2+1/3+1/4+...)
            isPrime[j]=false;
            highestPrime[j]=i;
            if(lowestPrime[j]==-1)lowestPrime[j]=i;
        }
    }
    return isPrime;
}

vector<ll> get_prime_factors(ll n){ // O(logn)
    vector<ll> prime_factors;
    while(n>1){
        ll prime_factor=highestPrime[n];
        while(n%prime_factor==0){
            prime_factors.push_back(prime_factor);
        }
    }
    return prime_factors;
}

// <--------------------------------- MODULAR ARITHMETIC ------------------------------------>

/* 
Fermat's Little Theorem - A ^ (M-1) = 1 mod (M) 
M is prime, A is not a multiple of M
(when M is not a prime then EEA-Extended Euclidean Algorithm)
1/A = A ^ (-1) = A^(M-2) mod (M)

linear diaphrantine equations
*/


ll pow(ll  base,ll exp,ll MOD){ll ans=1;while(exp>0){if(exp&1)ans=(ans*base)%MOD;base=(base*base)%MOD;exp>>=1;}return ans;}
ll inv(ll x){return pow(x,MOD-2,MOD);}
// mod for + - * /
ll add(ll a,ll b){return ((a%MOD)+(b%MOD))%MOD;}
ll sub(ll a,ll b){return ((a%MOD)-(b%MOD)+MOD)%MOD;}
ll mul(ll a,ll b){return ((a%MOD)*(b%MOD))%MOD;}
ll divmod(ll a,ll b){return mul(a,inv(b));}

// <-------------------------------------- FACTORIAL, COMBINATIONS ------------------------------->
// create a static function and precompute it once for all test cases for leetcode

vector<ll> get_fact(ll n){
    vector<ll>fact(n+1,1);
    for(ll i=1;i<=n;++i)fact[i]=(fact[i-1]*1LL*i)%MOD;
    return fact;
}

// choose exactly r out of n
ll get_comb(ll n,ll r){
    if(r>n||n<0||r<0)return 0;
    return divmod(fact[n],mul(fact[r],fact[n-r]));
}

void get_pascal_triange(){ // choose at most k out of n

}


// <--------------------------------------------------------------------->

int main(){
    FAST_IO;
    int  base,exp;cin>> base>>exp;
    cout<<(1<<30)<<endl;
    cout<<bin_exp_recur( base,exp)<<endl;
    cout<<bin_exp_iter( base,exp)<<endl; // O(log(exp))
}


// <-------------------------------------- LEETCODE USED TEMPLATES ------------------------------->


// divisors or factors
const int N=1e5;
vector<int> divisors[N+1]; // creates a array of N+1 vectors
void preDivisors(){for(int i=1;i<=N;++i)for(int j=i;j<=N;j+=i)divisors[j].push_back(i);} // nlogn
class Solution {
public:
    Solution(){preDivisors();}



// multiples
const int N=1e5;
vector<int> multiples[N+1]; // creates a array of N+1 vectors
void preMultiples(){for(int i=1;i<=N;++i)for(int j=i;j<=N;j+=i)multiples[i].push_back(j);} // nlogn
class Solution {
public:
    Solution(){preMultiples();}



// primes
const int N=1e5;
vector<bool> is_prime(N+1,1);
int prime_count[N+1];
void sieve(){is_prime[0]=is_prime[1]=0;for(int i=2;i*i<=N;++i)if(is_prime[i])for(int j=i*i;j<=N;j+=i)is_prime[j]=0;} // sqrtn
void pre(){int cnt=0;for(int i=2;i<=N;++i){cnt+=is_prime[i];prime_count[i]=cnt;}}
class Solution {
public:
    Solution(){sieve();pre();}


