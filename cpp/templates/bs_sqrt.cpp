#include "bits/stdc++.h"

using namespace std;

const double eps=1e-7;

int muln(double x,int n){
	double ans=1;
	while(n--)ans*=x;
	return ans;
}

int main(){
	double x;cin>>x;int n;cin>>n;
	double lo=1,hi=x,mid;
	while(hi-lo>eps){
		mid=lo+(hi-lo)/2;
		// mid=(lo+hi)/2;
		if(muln(mid,n)<x)lo=mid;
		else hi=mid;
	}
	cout<<setprecision(10)<<lo<<'\n'<<hi<<'\n';
	// cout<<pow(x,0.5)<<'\n';
	cout<<pow(x,1.0/n)<<'\n';
}