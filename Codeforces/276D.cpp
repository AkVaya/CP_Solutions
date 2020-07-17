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
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=5e6+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
ll binpow(ll a,ll b,ll m=inf) {
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
void solve(){
    ll l,r;
    cin>>l>>r;
    bitset<69> bs[3];
    bs[1]=bitset<69>(l);
    bs[0]=bitset<69>(r);
    bool check=false;
    ll first=-1;
    for (int i = 68; i >= 0; --i)
    {
        if(bs[0][i] != bs[1][i]){
            first=i;
            break;
        }
    }
    if(first>=0){
        for (int i = 0; i <= first; ++i)
        {
            bs[2][i]=1;
        }
    }
    cout<<bs[2].to_ullong()<<endl;
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