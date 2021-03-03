#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 2e5 + 69;
int main(){
	ll n;
	cin>>n;
	ll res = (n*n*n - n)/3 - 2;
	cout<<res<<'\n';
   	return 0;
}