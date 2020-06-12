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
const ll nax=1e7+1;
vector<ll> spf(nax);
void sieve(){
    for (int i = 1; i < nax; ++i)
    {
        spf[i]=i;
    }
    for (int i = 4; i < nax; i+=2)
    {
        spf[i]=2;
    }
    for (ll i = 3; i < nax; i+=2)
    {
        if (spf[i]==i)
        {
            for (ll j = i*i; j < nax; j+=i)
            {
                spf[j]=min(i,spf[j]);
            }
        }
    }
}
void solve(){
    ll n;
    cin>>n;
    sieve();
    ll a[n];
    vector<ll> v1(n,-1),v2(n,-1);
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        ll num=1;
        ll x=spf[a[i]];
        while(spf[a[i]]==x){
            num*=x;
            a[i]/=x;
        }
        if(a[i]>1){
            v1[i]=a[i];
            v2[i]=num;
        }
        else{
            v1[i]=-1;
            v2[i]=-1;
        }
    }
    for (int i = 0; i < v1.size(); ++i)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < v2.size(); ++i)
    {
        cout<<v2[i]<<" ";
    }
    cout<<endl;
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