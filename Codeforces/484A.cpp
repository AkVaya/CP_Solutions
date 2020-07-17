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
const ll nax=5e6+69;
const ll inf=9e18+69;
using pii = pair<ll,ll>;
void solve(){
    ll l,r,x=-1;
    cin>>l>>r;
    ll temp=r;
    bitset<69> bs[3];
    bs[0]=bitset<69>(r);
    bs[1]=bitset<69>(l);
    bs[2]=bitset<69>(0);
    bool check=false;
    ll pos=0;
    while(r){
        pos++;
        r>>=1;
    }
    for (int i = pos-1; i >= 0; --i)
    {
        if(!check && bs[0][i]==bs[1][i])
            bs[2][i]=bs[0][i];
        else if(!check && bs[0][i] && bs[1][i]==0){
            check=true;
            bs[2][i]=0;
        }
        else if(check)
            bs[2][i]=1;
    }
    r=temp;
    ll ans=(ll)((bs[2]).to_ullong());
    //cout<<ans<<" "<<__builtin_popcount(ans)<<" "<<__builtin_popcount(temp)<<endl;
    if(__builtin_popcountll(r)>__builtin_popcountll(ans))
        ans=r;
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