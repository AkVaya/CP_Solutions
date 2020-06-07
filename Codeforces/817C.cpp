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
ll fun(ll a){
    return a>0 ? a : -a ;
}
ll sum(ll x){
    ll ans=0;
    while(x){
        ans+=x%10;
        x/=10;
    }
    return ans;
}
void solve(){
    ll n,s,ans=0,r=inf,l=1;
    //ll count=0;
    cin>>n>>s;
    while(l<=r){
        ll mid=(l+r)/2;
        if(fun(mid-sum(mid))>=s)
            r=mid-1;
        else
            l=mid+1;
        //count++;
        //if(count>100)
          //  break;
        //cout<<l<<" "<<r<<endl;
    }
    ans=n-l+1;
    cout<<(ans >=0 ? ans : 0)<<endl;

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