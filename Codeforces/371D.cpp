#include<bits/stdc++.h> 
using namespace std; 
const int nax = 2e5 + 69;
using ll = long long;
ll a[nax], res[nax], par[nax], n;
void fun(ll x, ll y){
	int start = x;
	if(par[x]!=x)
		x = par[x];
	while(y>0 && x<=n){
		if(res[x]+y<=a[x]){
			res[x]+=y;
			if(res[x]==a[x])
				par[x] = x+1;
			break;
		}
		else{
			ll left = y - (a[x] - res[x]);
			res[x] = a[x];
			par[x] = x+1;
			x++;
			y = left;
		}
	}
	while(par[start]!=x){
		int temp = par[start];
		par[start] = x;
		start = temp;
		
	}

}
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for (int i = 1; i <= n; ++i)
    {
    	cin>>a[i];
    	res[i] = 0;
    	par[i] = i;
    }
    par[n+1] = n+1;
    ll q, t, x, y;
    cin>>q;
    while(q--){
    	cin>>t;
    	if(t==2){
    		cin>>x;
    		cout<<res[x]<<'\n';
    	}
    	else{
    		cin>>x>>y;
    		fun(x, y);
    	}
    }
	return 0;
} 