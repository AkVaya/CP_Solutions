#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#include<bitset>
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
const ll M =1e18;
const ll nax=2e6+5;
const ll inf=1e18;
using pii = pair<ll,ll>; 
long long binpow(long long a, long long b, long long m=M) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = ((res%m) * (a%m)) % m;
        a = ((a%m) * (a%m)) % m;
        b >>= 1;
    }
    return res;
}
bool custom(pii &p , pii & q){
    if(p.first!=q.first)
        return p.first>q.first;
    else
        return p.second<q.second;
}
void solve(){
    ll n,k;
    cin>>n>>k;
    bitset<30> bs[n],ans;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        bs[i]=bitset<30>(a[i]);
    }
    vector<pair<ll,ll> > v;
    for (int i = 0; i < 30; ++i)
    {
        ll cnt=0;
        for (int j = 0; j < n; ++j)
        {
            if(bs[j][i])
                cnt++;
        }
        v.pb({(cnt)*binpow(2,i),i});
    }
    sort(v.begin(), v.end(),custom);
    for (int i = 0; i < k; ++i)
    {
        ans[v[i].second]=1;
    }
    //for(auto i : v)
      //  cout<<i.first<<" "<< i.second<<endl;
    cout<<ans.to_ullong()<<endl;

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