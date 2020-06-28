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
vector<ll> val(64,0);
ll fun(char x){
    ll req;
    if(x>='0' && x<='9')
        req=x-'0';
    else if(x>='A' && x<='Z')
        req=x-'A'+10;
    else if(x>='a' && x<='z')
        req=x-'a'+36;
    else if(x=='-')
        req=62;
    else
        req=63;
    return req;
}
void solve(){
    string s;
    cin>>s;
    ll ans=1;
    for (int i = 0; i < 64; ++i)
    {
        for (int j = 0; j < 64; ++j)
        {
            ll x =(i&j);
            val[x]++;
            //if(x==63)
                //cout<<i<<" "<<j<<endl;
        }
    }
    //cout<<val[63]<<endl;
    //for (int i = 0; i < 64; ++i)
    //{
    //    cout<<i<<" "<<val[i]<<endl;
    //}
    for (int i = 0; i < s.length(); ++i)
    {
        //cout<<fun(s[i])<<" "<<val[fun(s[i])]<<endl;
        ans=(ans*val[fun(s[i])]%M)%M;
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