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
#define fr(i,a,b) for (int i = a; i < b; ++i)
using namespace std;
const ll M =1e9+7;
const ll nax=1e3+1;
void solve(){
    ll n;
    cin>>n;
    ll a[n],x;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin>>x;
        a[i]-=x;
    }
    vector<ll> c,d;
    for (int i = 0; i < n; i++)
        if (a[i] > 0)
            c.push_back(a[i]);
        else
            d.push_back(a[i]);
 
    sort(c.begin(), c.end());
    sort(d.rbegin(), d.rend());
    ll j = 0;
    ll ans = 0;
    for (int i = 0; i < c.size(); i++) {
        while (j < d.size() && c[i] + d[j] > 0)
            j++;
        ans += j;
    }
    j=c.size();
    ans += (j * (j- 1)) / 2;  
 
    cout << ans << endl;
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