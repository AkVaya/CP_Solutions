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
const ll nax=2e4+1;
bool vis[nax];
ll level[nax],n,m;
vector<vector<int > > v;
void bfs(int source){
    queue<int> q;
    vis[source]=true;
    q.push(source);
    level[source]=0;
    while(!q.empty()){
        ll p=q.front();
        if(p==m)
            return;
        q.pop();
        for (int i = 0; i < v[p].size(); ++i)
        {
            if(vis[v[p][i]]==false){
                vis[v[p][i]]=true;
                level[v[p][i]]=level[p]+1;
                q.push(v[p][i]);
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    memset(vis,false,sizeof(vis));
    v.resize(nax);
    for (int i = 1; i < 1e4+1; ++i)
    {
        v[i].pb(2*i);
        v[i].pb(i-1);
    }
    ll ans=0;
    bfs(n);
    cout<<level[m]<<endl;
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