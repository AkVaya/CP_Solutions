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
const ll M =1e9+7;
const ll nax=2e6+5;
const ll inf=1e18;
using pii = pair<ll,ll>;
ll ans[nax];
void solve(){
    ll n,k;
    cin>>n>>k;
    map<ll,ll> m;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for (int i = 1; i < n; ++i)
    {
        a[i]-=a[0];
    }
    a[0]=0;
    for (int i = 0; i < n; ++i)
    {
        m[a[i]]++;
    }
    for (int i = a[n-1]; i>0; --i)
    {
        m[i]+=m[i+1];
    }
    ll curr=0,ans=0;
    for (int i = a[n-1]; i>0; --i)
    {
        curr+=m[i];
        if(curr>k){
            ans++;
            curr=m[i];
        }
    }
    cout<<(curr>0 ? ans+1 : ans)<<endl;
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