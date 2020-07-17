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
#define pb push_back
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
const ll M =1e9+7;
const ll nax=2e3+5;
const ll inf=1e18;
using pii = pair<ll,ll>;
void solve(){
    ll n;
    cin>>n;
    ll a[n],ans=0;
    ll till[n+1][27];
    memset(till,0,sizeof(till));
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        till[i+1][a[i]]++;
    }
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= 26; ++j)
        {
            till[i][j]+=till[i-1][j];
        }
    }
    for (int i = 1; i <= 26; ++i)
    {
        ans=max(ans,till[n][i]);
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {

            ll cnt1=0,cnt2=0;
            for (int k = 1; k <= 26; ++k)
            {
                cnt1=max(cnt1,till[j+1][k]-till[i][k]);
                cnt2=max(cnt2,min(till[i][k],till[n][k]-till[j+1][k])*2);
            }
            ans=max(ans,cnt1+cnt2);
        }
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