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
#define Fi first
#define Se second
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
const ll nax=3e5;
const ll inf=1e18;
using pii = pair<ll,ll>;
vector<vector<ll> > v;
vector<pii> edges;
bool check=true;
vector<ll> side;
ll n;
void bfs(){
	queue<ll> q;
	for (int i = 1; i <= n; ++i)
	{
		if(side[i]==-1){
			side[i]=0;
			q.push(i);
			while(q.size()){
				ll p=q.front();
				q.pop();
				for(auto j : v[p]){
					if(side[j]==-1){
						side[j]=1-side[p];
						q.push(j);
					}
					else if(side[j]==side[p]){
						check=false;
						return;
					}
				}
			}
		}
	}
}
void solve(){
    ll m,x,y,ans=0;
    cin>>n>>m;
    string s;
    side.resize(n+1,-1);
    v.resize(n+1);
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
        edges.pb(mp(x,y));
    }
    bfs();
    if(!check){
    	cout<<"NO"<<endl;
    	return;
    }
    cout<<"YES"<<endl;
    for (auto i : edges)
    {
    	cout<<(char)(side[i.second]+'0');
    }
    cout<<endl;

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