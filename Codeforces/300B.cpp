#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<stdio.h>
#include<iomanip>
#include<bitset>
#include<algorithm>
#include<map>
#include<math.h>
#include<cstring>
#include<string>
#include<ctime>
#include<cmath>
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
#define fr(i,a,b) for (int i = a; i < b; ++i)
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=2e6+10;
vector<vector<ll> > v;
vector<bool> vis;
map<ll,vector<vector<ll> > > ans;
ll bfs(ll s){
    queue<ll> q;
    vis[s]=true;
    q.push(s);
    ll x=0;
    vector<ll> temp;
    temp.pb(s);
    while(!q.empty()){
        ll p=q.front();
        q.pop();
        for (auto i : v[p])
        {
            if(vis[i]==false){
                vis[i]=true;
                x++;
                q.push(i);
                temp.pb(i);
            }
        }
    }
    if(x>2)
        return -1;
    ans[x].pb(temp);
    return x;
}
void solve(){
    ll n,x,y,m;
    cin>>n>>m;
    v.resize(n+1);
    vis.resize(n+1,false);
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        //cout<<i<<endl;
        if(!vis[i]){
            if(bfs(i)<0){
                cout<<-1<<endl;
                return ;
            }
        }
    }
    if((ans[0].size()-ans[1].size())%3){
        cout<<-1<<endl;
        return;
    }
    else if(ans[1].size()>ans[0].size()){
        cout<<-1<<endl;
        return;
    }
    //cout<<"HERE"<<endl;
    for (int i = 0; i < ans[2].size(); ++i)
    {
        cout<<ans[2][i][0]<<" "<<ans[2][i][1]<<" "<<ans[2][i][2]<<endl;
    }
    for (int i = 0; i < ans[1].size(); i++)
    {
        cout<<ans[1][i][0]<<" "<<ans[1][i][1]<<" "<<ans[0][i][0]<<endl;
    }
    for (int i = ans[1].size(); i < ans[0].size(); i+=3)
    {
        cout<<ans[0][i][0]<<" "<<ans[0][i+1][0]<<" "<<ans[0][i+2][0]<<endl;
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