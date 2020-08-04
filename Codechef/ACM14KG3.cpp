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
const ll M =1e9+7;
const ll nax=1e5+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
vector<vector<ll> >v;
vector<bool> vis;
map<ll,set<ll> > m;
void dfs(ll s,ll x){
	m[x].ins(s);
	vis[s]=true;
	for(auto i : v[s]){
		if(!vis[i]){
			dfs(i,x);
		}
	}
}
void solve(){
	string s,t;
	cin>>s>>t;
	ll k;
	cin>>k;
	char x[4];
	v.resize(26);
	vis.resize(26,false);
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cin>>x[j];
		}
		v[x[0]-'a'].pb(x[3]-'a');
	}
	if (s.length()!=t.length())
	{
		cout<<"NO"<<endl;
		return;
	}
	for (int i = 0; i < 26; ++i)
	{
		dfs(i,i);
		vis.clear();
		vis.resize(26,false);
	}
	bool check=true;
	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i]!=t[i] && m[s[i]-'a'].find(t[i]-'a')==m[s[i]-'a'].end()){
			check=false;
		}
	}
	if(check)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	v.clear();
	vis.clear();
	m.clear();
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