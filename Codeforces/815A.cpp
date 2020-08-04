#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#include<iomanip>
#include<queue>
#define endl '\n'
#define pb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll ;
const ll M =998244353;
const ll nax=5e3+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
void solve(){
	ll n,m;
    cin>>n>>m;
    ll a[n][m];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin>>a[i][j];
    vector<pair<ll,pii> > ans;
    bool check=true;
    if(m>=n){
    	for (int i = 0; i < n; ++i)
    	{
    		ll mn=M;
    		for (int j = 0; j < m; ++j)
    			mn=min(mn,a[i][j]);
    		for (int j = 0; j < m; ++j)
    			a[i][j]-=mn;
    		if(mn){
    			ans.pb(mp(0,mp(mn,i)));
    		}
    	}
    	for (int j = 0; j < m; ++j)
    	{
    		for (int i = 0; i < n; ++i)
    		{
    			if(a[0][j]!=a[i][j]){
    				check=false;
    				break;
    			}
    		}
    		if(a[0][j])
    			ans.pb(mp(1,mp(a[0][j],j)));
    	}
    }
    else{
    	for (int j = 0; j < m; ++j)
    	{
    		ll mn=M;
    		for (int i = 0; i < n; ++i)
    			mn=min(mn,a[i][j]);
    		for (int i = 0; i < n; ++i)
    			a[i][j]-=mn;
    		if(mn){
    			ans.pb(mp(1,mp(mn,j)));
    		}
    	}
    	for (int i = 0; i < n; ++i)
    	{
    		for (int j = 0; j < m; ++j)
    		{
    			if(a[i][0]!=a[i][j]){
    				check=false;
    				break;
    			}
    		}
    		if(a[i][0])
    			ans.pb(mp(0,mp(a[i][0],i)));
    	}
    }
    if(!check)
    	cout<<-1<<endl;
    else{
    	ll cnt=0;
    	for(auto i : ans)
    		cnt+=i.second.first;
    	cout<<cnt<<endl;
    	for(auto j : ans){
    		for (int i = 0; i < j.second.first; ++i)
    		{
    			if(j.first)
    				cout<<"col ";
    			else
    				cout<<"row ";
    			cout<<j.second.second+1<<endl;
    		}
    	}
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //#ifndef ONLINE_JUDGE 
      //  freopen("input.txt", "r", stdin); 
      //  freopen("output.txt", "w", stdout); 
    //#endif 

    ll t=1,t1=1;
    //cin>>t;
    //clock_t t3 = clock();
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    //clock_t t2 = clock();
    //cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
    //cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}