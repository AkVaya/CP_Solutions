#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<map>
#include<math.h>
#include<string.h>
#include<ctime>
#include<cmath>
#define ll long long
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
#define fr(i,a,b) for (int i = a; i < b; ++i)
using namespace std;
const ll M =1e9+7;
const ll nax=1e5+1;
bool vis[100005];
ll level[100005];
vector<vector<ll > > v;
vector<ll> ans;
void bfs(ll s){
    priority_queue<ll,vector<ll>,greater<int>> q;
    vis[s]=true;
    q.push(s);
    //ans.pb(s);
    while(!q.empty()){
        ll p=q.top();
        q.pop();
        ans.pb(p);
        for (int i = 0; i < v[p].size(); ++i)
        {
            if(vis[v[p][i]]==false){
                vis[v[p][i]]=true;
                q.push(v[p][i]);
            }
        }
    }
}
void solve(){
    ll n,m,x,y;
    cin>>n>>m;
    v.resize(n+1);
    //vis.resize(n+1);
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    bfs(1);
    for(auto i : ans)
        cout<<i<<" ";
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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