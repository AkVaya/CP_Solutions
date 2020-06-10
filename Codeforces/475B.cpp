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
#define pf push_front
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
#define fr(i,a,b) for (int i = a; i < b; ++i)
using namespace std;
const ll M =1e9+7;
const ll nax=25;
bool vis[nax][nax];
vector<pair<ll,ll> > v[nax][nax];
ll n,m,cnt;
void dfs(ll source, ll dest){
    vis[source][dest]=true;
    cnt++;
    for (int i = 0; i < v[source][dest].size(); ++i)
    {
        ll fi=v[source][dest][i].first,se=v[source][dest][i].second;
        if(!vis[fi][se]){
            dfs(fi,se);
        }
    }
}
void solve(){
    cin>>n>>m;
    char x;
    //fill(vis.begin(), vis.end(),false);
    for (int i = 1; i <= n; ++i)
    {
        cin>>x;
        if(x=='>'){
            for (int j = 1; j < m; ++j)
            {
                v[i][j].pb(mp(i,j+1));
            }
        }
        else{
            for (int j = 2; j <= m; ++j)
            {
                v[i][j].pb(mp(i,j-1));
            }
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        cin>>x;
        if(x=='^'){
            for (int j = 2; j <= n; ++j)
            {
                v[j][i].pb(mp(j-1,i));
            }
        }
        else if(x=='v'){
            for (int j = 1; j < n; ++j)
            {
                v[j][i].pb(mp(j+1,i));
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cnt=0;
            memset(vis,false,sizeof(vis));
            dfs(i,j);
            if(cnt!=m*n){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    
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