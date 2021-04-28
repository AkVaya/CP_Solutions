#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
const ll M = 1e9 + 7;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,x,y;
		cin>>n>>x>>y;
		int s = x + y;
		cout<<max(1,min(s - n + 1,n))<<' '<<min(n,x+y-1)<<'\n';	
	}
	return 0;
}