#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<string.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 998244353
using namespace std;
ll h,w;
ll x_axis[8]={-1,-1,-1,0,0,1,1,1};
ll y_axis[8]={-1,0,1,-1,1,1,0,-1};
char a[51][51];
bool vis[51][51];
ll dist[51][51];
ll dfs(ll i,ll j,ll count){
    if(vis[i][j])
        return dist[i][j];
    dist[i][j]=1+count;
    vis[i][j]=true;
    ll x,y,z=count+1;
    //cout<<a[0][0]<<endl;
    for (int k = 0; k < 8; ++k)
    {
        x=i+x_axis[k];
        y=j+y_axis[k];
        //cout<<x<<" Y: "<<y<<endl;
       // if(x>=0 && x<h && y>=0 && y<w)
         //   cout<<x<<" "<<y<<endl;
        if(x>=0 && x<h && y>=0 && y<w && a[x][y]==a[i][j]+1){
            //cout<<a[x][y];
            z=max(dfs(x,y,count+1),z);
        }
    }
    return z;
}
void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    while(1){
        cin>>h>>w;
        if(!h && !w)
            return;
        //count=0;
        memset(vis,false,sizeof(vis));
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                cin>>a[i][j];
            }
        }
        ll ans=0;
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if(a[i][j]=='A'){
                    ans=max(ans,dfs(i,j,0));
                }
            }
        }
        cout<<"Case "<<t++<<": "<<ans<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--){        
        solve();
    }
    return 0 ;
}