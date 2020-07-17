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
#define endl '\n'
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
const ll nax=5e6+5;
const ll inf=9e18;
using pii = pair<ll,ll>;
ll cnt[nax],spd[nax];
void sieve(){
    spd[0]=spd[1]=1;
    for (int i = 1; i < nax; i++)
    {
        if(i%2)
            spd[i]=i;
        else
            spd[i]=2;
    }
    for (ll i = 3; i <nax; i+=2)
        if (spd[i]==i)
            for (ll j = i*i; j < nax; j+=i)
                spd[j]=min(spd[j],i);
}
void factorize(ll n){
    ll temp=n;
    while(n>1){
        n/=spd[n];
        cnt[temp]++;
    }
}
void solve(){
    ll a,b;
    cin>>a>>b;
    //cout<<cnt[b]<<" "<<cnt[a]<<" ";
    cout<<cnt[a]-cnt[b]<<endl;

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
    sieve();
    for (int i = 1; i < nax; ++i)
    {
        factorize(i);
        cnt[i]+=cnt[i-1];
    }
    cin>>t;
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    //clock_t t2 = clock();
    //cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
    //cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}