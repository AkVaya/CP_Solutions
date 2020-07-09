#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#include<iomanip>
#include<queue>
#define pb push_back
#define Fir first
#define Sec second
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll ;
const ll M =998244353;
const ll nax=3e5;
const ll inf=9e18;
using pii = pair<ll,ll>;
ll val(ll a,ll b,ll c){
    return (a-b)*(a-b) + (b-c)*(b-c) + (c-a)*(c-a) ;
}
void solve(){
    ll x,y,z;
    cin>>x>>y>>z;
    ll a[x+1],b[y+1],c[z+1];
    for (int i = 0; i < x; ++i)
    {
        cin>>a[i];
    }
    a[x]=0;
    sort(a,a+x);
    for (int i = 0; i < y; ++i)
    {
        cin>>b[i];
    }
    b[y]=0;
    sort(b,b+y);
    for (int i = 0; i < z; ++i)
    {
        cin>>c[i];
    }
    c[z]=0;
    sort(c,c+z);
    ll ans=inf;
    ll ind1,ind2;
    for (int i = 0; i < x; ++i)
    {
        ind1=lower_bound(b,b+y,a[i])-b;
        ind2=lower_bound(c,c+z,a[i])-c;
        ans=min(ans,val(a[i],b[ind1],c[ind2]));
        if(ind1){
            ans=min(ans,val(a[i],b[ind1-1],c[ind2]));
            if(ind2)
                ans=min(ans,val(a[i],b[ind1-1],c[ind2-1]));
        }
        if(ind2)
            ans=min(ans,val(a[i],b[ind1],c[ind2-1]));
    }
    for (int i = 0; i < y; ++i)
    {
        ind1=lower_bound(a,a+x,b[i])-a;
        ind2=lower_bound(c,c+z,b[i])-c;
        ans=min(ans,val(a[ind1],b[i],c[ind2]));
        if(ind1){
            ans=min(ans,val(a[ind1-1],b[i],c[ind2]));
            if(ind2)
                ans=min(ans,val(a[ind1-1],b[i],c[ind2-1]));
        }
        if(ind2)
            ans=min(ans,val(a[ind1],b[i],c[ind2-1]));
    }
    for (int i = 0; i < z; ++i)
    {
        ind1=lower_bound(a,a+x,c[i])-a;
        ind2=lower_bound(b,b+y,c[i])-b;
        ans=min(ans,val(a[ind1],b[ind2],c[i]));
        if(ind1){
            ans=min(ans,val(a[ind1-1],b[ind2],c[i]));
            if(ind2)
                ans=min(ans,val(a[ind1-1],b[ind2-1],c[i]));
        }
        if(ind2)
            ans=min(ans,val(a[ind1],b[ind2-1],c[i]));
    }
    cout<<ans<<endl;
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
    cin>>t;
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