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
typedef long long ll;
const ll M =1e9+7;
const ll nax=1e5+1;
vector<bool> vis;
vector<vector<ll> > v;
ll n;
double ans[nax];
void dfs(ll s){
    if(vis[s])
        return;
    vis[s]=true;
    if(v[s].size()==1 && s!=1){
        ans[s]=0;
        return ;
    }
    ans[s]=0;
    for (int i = 0; i < v[s].size(); ++i)
    {
        if(!vis[v[s][i]]){
            dfs(v[s][i]);
            ans[s]+=ans[v[s][i]];
        }
    }
    if(s!=1)
        ans[s]/=(double(v[s].size())-1.0);
    else 
        ans[s]/=v[s].size();
    ans[s]++;
    //cout<<s<<" "<<ans[s]<<endl;
}
void solve(){
    cin>>n;
    v.resize(n+1);
    vis.resize(n+1);
    fill(vis.begin(), vis.end(),false);
    ll x,y;
    for (int i = 0; i < n-1; ++i)
    {
        ans[i+1]=0.0;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    ans[n]=0.0;
    if(n==1)
        cout<<fixed<<setprecision(10)<<0.0<<endl;
    else{
        dfs(1);
        cout<<fixed<<setprecision(10)<<ans[1]<<endl;
    }
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