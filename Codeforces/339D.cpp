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
const ll M =1e8;
const ll nax=3e5;
const ll inf=1e18;
using pii = pair<ll,ll>;
ll n,Segment_Tree[4*nax],a[nax];
void build(ll curr,ll tl,ll tr){
    if(tl==tr)
        Segment_Tree[curr]=a[tl];
    else{
        ll tm=(tl+tr)/2;
        build(curr*2,tl,tm);
        build(curr*2+1,tm+1,tr);
        ll lvl = (float)((log(curr)/log(2)));
        if(n%2)
            lvl--;
        if(lvl%2){
            Segment_Tree[curr]=Segment_Tree[2*curr]|Segment_Tree[2*curr+1];
        }
        else
            Segment_Tree[curr]=Segment_Tree[2*curr]^Segment_Tree[2*curr+1];

    }
}
void update(ll curr,ll tl,ll tr,ll pos, ll val){
    if(tl==tr)
        Segment_Tree[curr]=val;
    else{
        ll tm=(tl+tr)/2;
        if(pos<=tm)
            update(2*curr,tl,tm,pos,val);
        else
            update(2*curr+1,tm+1,tr,pos,val);

        ll lvl = (float)((log(curr)/log(2)));
        if(n%2)
            lvl--;
        if(lvl%2){
            Segment_Tree[curr]=Segment_Tree[2*curr]|Segment_Tree[2*curr+1];
        }
        else
            Segment_Tree[curr]=Segment_Tree[2*curr]^Segment_Tree[2*curr+1];
    }
}
void solve(){
    ll m;
    cin>>n>>m;
    ll pw=pow(2,n);
    //cout<<((1^6)|(3^5))<<endl;
    for (int i = 0; i < pw; ++i)
    {
        cin>>a[i];
    }
    build(1,0,pw-1);
    //cout<<Segment_Tree[1]<<endl;
    ll x,y;
    for (int i = 0; i < m; ++i)
    {
        cin>>x>>y;
        update(1,0,pw-1,x-1,y);
        cout<<Segment_Tree[1]<<endl;
        //cout<<endl;
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