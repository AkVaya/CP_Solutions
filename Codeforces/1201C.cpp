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
const ll nax=2e5+1;
ll n,k;
ll a[nax];
bool check(ll x){
    ll val=0;
    for (int i = n/2; i < n; ++i)
    {
        if(x-a[i]>0)
            val+=x-a[i];
    }
    if(val>k)
        return false;
    return true;
}
void solve(){
    cin>>n>>k;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    ll l=1,r=2e9;
    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid))
            l=mid+1;
        else
            r=mid-1;
    }
    cout<<l-1<<endl;
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