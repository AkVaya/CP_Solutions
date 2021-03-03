#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
	while(t--){ 
	    ll x,y;
	    ll res = 0;
	    cin>>x>>y;
	   	for (int i = 1; i <= sqrt(x); ++i)
	   	{
	   		if(i>=y)
	   			break;
	   		ll val =(min(y,(x-i)/i)-i);
	   		if(val<0)
	   			break;
	   		res+=val;
	   	}
	   	cout<<res<<'\n';
	}
    return 0;
}