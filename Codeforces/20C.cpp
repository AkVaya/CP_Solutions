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
const ll inf=1e18;
using pii = pair<ll,ll>;
vector<vector<ll> > v;
vector<ll> dist,path;
map<pii,ll> ma;
void dijkstra(ll s){
    priority_queue<ll>pq;
    dist[s]=0;
    pq.push(s);
    path[s]=s;
    while(!pq.empty()){
        ll q = pq.top();
        pq.pop();
        for(auto j : v[q]){
            ll edge = j;
            ll val = ma[{q,j}];
            if(dist[edge]> dist[q]+val){
                dist[edge]=dist[q]+val;
                pq.push(edge);
                path[edge]=q;
            }
        }
    }
}
int main(){
    ll n,m,x,y,z;
    cin>>n>>m;
    v.resize(n+1);
    path.resize(n+1,-1);
    dist.resize(n+1,inf);
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y>>z;
        v[x].push_back(y);
        v[y].push_back(x);
        ma[{x,y}]=z;
        ma[{y,x}]=z;
    }
    dijkstra(1);
    if(dist[n]==inf){
        cout<<-1<<endl;
        return 0;
    }
    else{
        vector<ll> ans;
        ans.pb(n);
        ll edge=n;
        while(path[edge]!=edge){
            ans.pb(path[edge]);
            edge=path[edge];
        }
        reverse(ans.begin(), ans.end());
        for(auto i :ans)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}