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
#define Se second
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
const ll nax=2e5+5;
const ll inf=9e18;
using pii = pair<ll,ll>;
ll fact[nax];
ll binpow(ll a,ll b,ll m=M) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = ((res%m) * (a%m)) % m;
        a = ((a%m) * (a%m)) % m;
        b >>= 1;
    }
    return res;
}
void mult(ll &a,ll b){
    a*=b;
    a%=M;
}
ll comb(ll a,ll b){
    ll val=1;
    mult(val,fact[a]);
    mult(val,binpow(fact[b],M-2));
    if(a-b>=0)
        mult(val,binpow(fact[a-b],M-2));
    return val;
}
void solve(){
    ll n,x;
    cin>>n>>x;
    ll ans=1;
    mult(ans,comb(x,n-1));
    //cout<<comb(x,n-1)<<endl;
    mult(ans,n-2);
    mult(ans,binpow(2,n-3));
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
    fact[0]=fact[1]=1;
    for (int i = 2; i < nax; ++i)
        fact[i]=(fact[i-1]*i)%M;
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