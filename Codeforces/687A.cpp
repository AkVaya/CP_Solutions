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
vector<ll> belong;
ll n,m,a=0;
bool check=true;
void bfs(ll s){
    queue<ll> q;
    vis[s]=true;
    belong[s]=0;
    //cout<<s<<" "<<ind<<endl;
    q.push(s);
    while(!q.empty()){
        ll p=q.front();
        q.pop();
        for (int i : v[p])
        {
            if(belong[i]==-1){
                belong[i]=1-belong[p];
            }
            else{
                check&=(belong[p]!=belong[i]);
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    v.resize(n+1);
    vis.resize(n+1);
    belong.resize(n+1);
    for (int i = 1; i <= n; ++i)
    {
        vis[i]=false;
        belong[i]=-1;
    }
    ll x,y;
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    queue<ll> q;
    vector<ll> v1,v2;
    for (int i = 1; i <= n; ++i)
    {
        if(belong[i]==-1){
            belong[i]=0;
            q.push(i);
            while(!q.empty()){
                ll p=q.front();
                q.pop();
                for (int i : v[p])
                {
                    if(belong[i]==-1){
                        belong[i]=1-belong[p];
                        q.push(i);
                    }
                    else{
                        check&=(belong[p]!=belong[i]);
                    }
                }
            }
        }
        if(belong[i]==1 && v[i].size())
            v1.pb(i);
        else if(v[i].size())
            v2.pb(i);
    }
    if(check){
        cout<<v1.size()<<endl;
        for(auto i: v1)
            cout<<i<<" ";
        cout<<endl<<v2.size()<<endl;
        for(auto i: v2)
            cout<<i<<" ";
        cout<<endl;

    }
    else
        cout<<-1<<endl;
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