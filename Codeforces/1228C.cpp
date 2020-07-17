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
#define endl '\n'
#define Fir first
#define Sec second
#define pb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=5e6+5;
const ll inf=9e18;
using pii = pair<ll,ll>;
ll n,x;
ll binpow(ll a,ll b,ll m=M) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = ((res%m) * (a%m)) % m;
        a = ((a%m) * (a%m)) % m;
        b >>= 1;
    }
    return res%m;
}
void mult(ll &a,ll b){
    a*=b;
    a%=M;
}
void solve(){
    cin>>x>>n;
    ll ans=1,temp=2;
    vector<ll>  primes;
    if(x%2==0)
        primes.pb(2);
    while(x%2==0){
        x/=2;
    }
    for (int i = 3; i <= sqrt(x); i+=2)
    {
        if(x%i==0){
            primes.pb(i);
            while(x%i==0)
                x/=i;
        }
    }
    if(x>1){
        primes.pb(x);
    }
    for(auto i : primes){
        //cout<<i<<" ";
        ll temp=n,a=0;
        while(temp){
            a+=temp/i;
            temp/=i;
        }
        //cout<<a<<endl;
        mult(ans,binpow(i,a));
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

    //clock_t t3 = clock();
    ll t=1,t1=1;
    //for (int i = 1; i < nax; ++i)
    //{
    //    factorize(i);
    //    cnt[i]+=cnt[i-1];
    //}
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