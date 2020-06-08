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
#define pf push_front
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
#define fr(i,a,b) for (int i = a; i < b; ++i)
using namespace std;
const ll M =1e9+7;
const ll nax=1e3+1;
long long binpow(long long a, long long b, long long m=inf) {
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
void solve(){
    ll n;
    cin>>n;
    ll a[n],pref[n],suff[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        if(i)
            pref[i]=(pref[i-1])&(~a[i]);
        else
            pref[0]=~a[0];
        //cout<<pref[i]<<" ";
    }
    //cout<<endl;
    suff[n-1]=~a[n-1];;
    for (int i = n-2; i >= 0; --i)
    {
        suff[i]=(suff[i+1])&(~a[i]);
        //cout<<suff[i]<<" ";
    }
    ll max=0,ind=0;
    for (int i = 0; i < n; ++i)
    {
        ll temp=a[i];
        if(i)
            temp&=pref[i-1];
        if(i<n-1)
            temp&=suff[i+1];
        if(max<temp){
            max=temp;ind=i;
        }
    }
    cout<<a[ind]<<" ";
    for (int i = 0; i < n; ++i)
    {
        if(i!=ind)
            cout<<a[i]<<" ";
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
    //cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
    //cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}