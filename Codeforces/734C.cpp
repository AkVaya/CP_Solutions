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
const ll nax=1e6+1;
ll a[nax],b[nax],spells[nax],costs[nax];
ll n,m,k,x,s;
void solve(){
    cin>>n>>m>>k>>x>>s;
    for (int i = 0; i < m; ++i)
        cin>>a[i];
    for (int i = 0; i < m; ++i)
        cin>>b[i];
    for (int i = 0; i < k; ++i)
        cin>>spells[i];
    for (int i = 0; i < k; ++i)
        cin>>costs[i];
    ll ans=n*x;
    for(int i=0;i<m;i++){
        ll cost=0;
        ll x1=b[i];
        if(x1>s)
            continue;
        ll x2=s-x1;
        ll ind=upper_bound(costs,costs+k,x2)-costs;
            ind--;
        if(ind<0)
            cost=a[i]*n;
        else{
            cost=min((a[i]*n),(n-spells[ind])*a[i]);
        }
        ans=min(ans,cost);
    }
    for(int i=0;i<k;i++){
        if(costs[i]>s)
            break;
        ll k2=(n-spells[i])*x;
        ans=min(k2,ans);
    }
    cout<<ans<<endl;
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