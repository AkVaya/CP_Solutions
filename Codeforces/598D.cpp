#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<bitset>
#include<vector>
#include<iomanip>
#include<queue>
#include<unordered_set>
//#define endl '\n'
#define Fir first
#define Sec second
#define pb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
#define LB lower_bound
#define UB upper_bound
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-base)
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
typedef long long ll ;
const ll M =1e9+7;
const ll nax=1e3+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
char a[nax][nax];
ll n,m,k;
vector<vector<ll> >vis(nax,vector<ll>(nax,0));
map<pii,pii> parent;
map<pii,ll> ans;
ll dfs(pii curr,pii p,ll clr){
    ll x=curr.Fir,y=curr.Sec;
    ll val=0;
    parent[curr]=p;
    vis[x][y]=clr;
    //cout<<x<<" "<<y<<endl;
    if(x<n-1){
        if(a[x+1][y]=='.' && vis[x+1][y]!=clr){
            val+=dfs({x+1,y},p,clr);
        }
        else if(a[x+1][y]=='*'){
            //cout<<x+1<<" "<<y<<endl;
            val++;
            vis[x+1][y]=clr;
        }
    }
    if(y<m-1){
        if(a[x][y+1]=='.' && vis[x][y+1]!=clr){
            val+=dfs({x,y+1},p,clr);
        }
        else if(a[x][y+1]=='*'){
            //cout<<x<<" "<<y+1<<endl;
            val++;
            vis[x][y+1]=clr;
        }
    }
    if(x>0){
        if(a[x-1][y]=='.' && vis[x-1][y]!=clr){
            val+=dfs({x-1,y},p,clr);
        }
        else if(a[x-1][y]=='*'){
            //cout<<x-1<<" "<<y<<endl;
            val++;
            vis[x-1][y]=clr;
        }
    }
    if(y>0){
        if(a[x][y-1]=='.' && vis[x][y-1]!=clr){
            val+=dfs({x,y-1},p,clr);
        }
        else if(a[x][y-1]=='*'){
            //cout<<x<<" "<<y-1<<endl;
            val++;
            vis[x][y-1]=clr;
        }
    }
    return val;
}
void solve(){ 
    cin>>n>>m>>k;
    for ( int i = 0; i < n; ++i){
        for ( int j = 0; j < m; ++j){
            cin>>a[i][j];
        }
    }
    //cout<<"YAHA"<<endl;
    ll curr=1;
    for ( int i = 0; i < n; ++i){
        for ( int j = 0; j < m; ++j){
            if(a[i][j]=='.' && !vis[i][j]){
                //cout<<i<<" "<<j<<" : "<<endl;
                ans[{i,j}]=dfs({i,j},{i,j},curr++);
                //cout<<i<<" "<<j<<" "<<ans[{i,j}]<<endl;
            }
        }
    }
    //cout<<"AB : YAHAN "<<endl;
    while(k--){
        ll x,y;
        cin>>x>>y;
        cout<<ans[parent[{x-1,y-1}]]<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //#ifndef ONLINE_JUDGE 
      //  freopen("input.txt", "r", stdin); 
      //  freopen("output.txt", "w", stdout); 
    //#endif 

    //clock_t t3 = clock();
    ll t=1,t1=1;
    //cin>>t;
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    //clock_t t2 = clock();
    //cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
    //cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}