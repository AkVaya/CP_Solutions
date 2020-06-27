#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#include<queue>
#define pb push_back
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=300+5;
using pii = pair<ll,ll>;
vector<bool>vis;
vector<vector<ll> > v;
char can[nax][nax];
vector<ll> x;
ll n;
void dfs(ll s){
    x.pb(s);
    vis[s]=true;
    for (int i = 0; i < n; ++i)
    {
        if(!vis[i] && can[s][i]=='1')
            dfs(i);
    }
}
void solve(){
    cin>>n;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    v.resize(n);
    vis.resize(n,false);
    for (int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n ; ++j ){
            cin>>can[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if(!vis[i]){
            dfs(i);
            vector<ll> val;
            for (int i = 0; i < x.size(); ++i)
            {
                val.eb(a[x[i]]);
                //cout<<x[i]<<" ";
            }
            //cout<<endl;
            sort(val.begin(), val.end());
            sort(x.begin(), x.end());
            for (int i = 0; i < x.size(); ++i)
            {
                a[x[i]]=val[i];
            }
            x.clear();
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout<<a[i]<<" ";
    }
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