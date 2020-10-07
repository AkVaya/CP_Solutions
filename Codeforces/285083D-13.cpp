#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#include<bitset>
#include<iomanip>
#include<queue>
#define endl '\n'
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=1e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
ll n,m,d;
vector<vector<pii> > v;
vector<ll> ans;
bool dfs(ll s,ll mx,ll cnt){
	//cout<<s<<' '<<cnt<<endl;
	if(s==n && cnt<=d){
		return true;
	}
	if(cnt>d)
		return false;
	for(auto i : v[s]){
		if(i.second<=mx){
			ans.pb(i.first);
			if(dfs(i.first,mx,cnt+1))
				return true;
			ans.pop_back();
		}
	}
	return false;
}
void solve(){
    cin>>n>>m>>d;
    ll x,y,z;
    v.resize(n+1);
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y>>z;
        v[x].pb({y,z});
    }    
    ll l = 0, r = 1e9;
	ans.pb(1);
    while(l<=r){
    	ll mid = (l+r)/2;
        if(dfs(1,mid,0))
            r = mid-1;
        else 
            l = mid+1;
        ans.clear();
        ans.pb(1);
    }
    dfs(1,r+1,0);
    if(ans.size()>1){
    	cout<<ans.size()-1<<endl;
    	for(auto i : ans)
    		cout<<i<<' ';
    	cout<<endl;
    }
    else cout<<-1<<endl;
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