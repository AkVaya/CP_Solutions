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
//#define endl '\n'
#define pb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=2e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
vector<vector<pii> > v;
ll val=0;
multiset<pair<ll,pii> > se;
ll dfs(ll s,ll p){
	ll temp=0;
	for(auto i : v[s]){
		if(i.first!=p){
			ll cnt=dfs(i.first,s);
			val+=cnt*i.second;
			//cout<<i.second<<' '; 
			//cout<<s<<' '<<i.first<<' '<<cnt<<' '<<val<<endl;
			se.ins(mp((i.second-i.second/2)*cnt,mp(i.second,cnt)));
			temp+=cnt;
		}
	}
	if(temp==0){
		//cout<<s<<endl;
		return 1;
	}
	return temp;
}
void solve(){
	ll n,S,x,y,z;
	cin>>n>>S;
	v.resize(n+1);
	for (int i = 0; i < n-1; ++i)
	{
		cin>>x>>y>>z;
		v[x].pb(mp(y,z));
		v[y].pb(mp(x,z));
	}
	val=0;
	dfs(1,1);
//	for(auto i : se)
//		cout<<i.first<<' '<<i.second<<endl;
//	cout<<val<<endl;
	ll ans=0;

	while(val>S){
		auto it=se.end();
		--it;
		val-=it->first;
		ll x=it->second.first;
		ll y=x/2;
		se.ins(mp(((y-y/2)*it->second.second),mp(y,it->second.second)));
		//cout<<val<<endl;
		se.erase(it);
		ans++;
		//if(ans==10)
		//	break;
	}
	cout<<ans<<endl;
	v.clear();
	se.clear();
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
     cin>>t;
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