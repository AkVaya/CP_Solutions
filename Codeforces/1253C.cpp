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
#define ll long long
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
using namespace std;
const ll M =1e9+7;
const ll nax=1e2+1;
void solve(){
    ll n,m,sum=0;
    cin>>n>>m;
    ll a[n+1],b=m-1,ind=2;
    for (int i = 1; i <=n; ++i)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll ans[n+1];
    ans[1]=a[1];
    sum=a[1];
    while(b--){
        ans[ind]=ans[ind-1]+a[ind];
        sum+=a[ind];
        ind++;
    }
    for (int i = m+1; i <=n; ++i)
    {
        sum+=a[i];
        ans[i]=ans[i-m]+sum;;
    }
    for (int i = 1; i <=n; ++i)
    {
        cout<<ans[i]<<" ";
    }
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
   // cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
   // cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}