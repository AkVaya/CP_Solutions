#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<map>
#include<math.h>
#include<string.h>
#include<ctime>
#include<cmath>
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
#define fr(i,a,b) for (int i = a; i < b; ++i)
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=1e5+1;
void solve(){
    ll n;
    cin>>n;
    ll a[n+1],lvl[n+1],cnt[n+1];
    lvl[1]=1;
    cnt[1]=1;
    for (int i = 2; i <= n; ++i)
        cnt[i]=0;
    for (int i = 2; i <= n; ++i)
    {
        cin>>a[i];
        lvl[i]=1+lvl[a[i]];
        cnt[lvl[i]]++;
        //cout<<lvl[i]<<" "<<cnt[lvl[i]]<<endl;
    }
    ll ans=0;
    for (int i = 1; i <= n; ++i)
    {
        ans+=cnt[i]%2;
    }
    cout<<ans<<endl;
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