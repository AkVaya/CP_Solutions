#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll a[n+69]={0};
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i];
    }
    if(n==1){
    	cout<<1<<'\n';
    	return 0;
    }
    int f = 0, s = 0,res = 0;
    for (int i = 0; i < n; ++i)
    {
    	if(a[i]==f){
    		if(a[i]!=s)
	    		res++;
	    	s = a[i];
    	}
    	else if(a[i]==s){
    		if(a[i]!=f)
    			res++;
    		f = a[i];
    	}
    	else if(a[i+1]==f){
    		res++;
    		f = a[i];
    	}
    	else if(a[i+1]==s){
    		res++;
    		s = a[i];
    	}
    	else{
    		f = a[i];
    		res++;
    	}
    }
    cout<<res<<'\n';
    return 0;
}