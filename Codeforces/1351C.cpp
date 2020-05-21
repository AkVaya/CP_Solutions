#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#define pb push_back
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define ll long long 
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 998244353
using namespace std;
void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    ll ans=0,x=0,y=0,tempx,tempy;
    set<pair<pair<ll,ll>,pair<ll,ll> > >se;
    //se.ins(mp(0,0));
    for (int i = 0; i < s.length(); ++i)
    {
        tempx=x;
        tempy=y;
        if(s[i]=='N')
            y++;
        else if(s[i]=='S')
            y--;
        else if(s[i]=='E')
            x++;
        else
            x--;
        if(se.find({{tempx,tempy},{x,y}})==se.end() && se.find({{x,y},{tempx,tempy}})==se.end()){
            se.ins({{tempx,tempy},{x,y}});
            ans+=5;
        }
        else ans++;
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n,q,x;
    cin>>t;
    while(t--){        
        solve();
    }
    return 0 ;
}