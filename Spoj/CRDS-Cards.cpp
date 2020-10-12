#include<bits/stdc++.h>
using namespace std;
long long int M = 1e6+7; 
void mult(long long &a, long long b){
	a*=b;
	a%=M;
}
void add(long long &a, long long b){
	a+=b;
	a%=M;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long t,n;
	cin>>t;
	while(t--){
		cin>>n;
		long long ans = 1;
		mult(ans,3*((n)*(n-1))/2);
		add(ans,2*n);
		cout<<ans<<'\n'; 
	}

	
}