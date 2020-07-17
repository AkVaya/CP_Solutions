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
// find_by_order(k): returns an iterator to the kth largest element (0-based)
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=1e7+1;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
ll cnt[nax];
ll spf[nax];
void sieve(){
    spf[0]=spf[1]=1;
    for (int i = 2; i < nax; ++i)
    {
        if(i%2)
            spf[i]=i;
        else
            spf[i]=2;
    }
    //cout<<"1YAHA"<<endl;
    for (ll i = 3; i < nax; i+=2)
    {
        if(spf[i]==i){
            //cout<<i<<endl;
            for (ll j = i*i; j < nax; j+=i)
            {
                if(spf[j]==j)
                    spf[j]=i;
            }
        }
    }
    //cout<<"   2YAHA   "<<endl;
}
void factorize(ll a){
    while(a>1){
        ll curr=spf[a];
        while(spf[a]==curr)
            a/=spf[a];
        cnt[curr]++;
    }
}
void solve(){ 
    ll n,m,x,y;
    cin>>n;
    ll a[n],mx=0;
    //cout<<"HMM"<<endl;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        mx=max(a[i],mx);
        factorize(a[i]);
    }
    cin>>m;
    //cout<<"YAHA "<<endl;
    for (int i = 3; i < nax; ++i)
    {
        cnt[i]+=cnt[i-1];
    }
    //cout<<"HERE"<<endl;
    while(m--){
        cin>>x>>y;
        if(x>mx)
            cout<<0<<endl;
        else
            cout<<cnt[min(y,mx)]-cnt[x-1]<<endl;
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
    sieve();
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    //clock_t t2 = clock();
    //cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
    //cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}