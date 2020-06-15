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
const ll nax=1e3+1;
vector<bool> v(nax);
vector<ll> x;
void sieve(){
    v[0]=false;
    v[1]=false;
    x.emplace_back(2);
    for (ll i = 3; i <nax; i+=2)
    {
        if (v[i]==true)
        {
            x.emplace_back(i);
            for (ll j = i*i; j < nax; j+=i)
            {
                v[j]=false;
            }
        }
    }
}
void solve(){
    ll n;
    cin>>n;
    ll a[n];
    vector<ll>clr(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<x.size();j++){
            if(a[i]%x[j]==0){
                clr[i]=j;
                break;
            }
        }    
    }
    set<ll>s;
    for(auto i:clr)
        s.insert(i);
    map<ll,ll>m;
    ll cnt=0;
    for(auto i:s)m[i]=++cnt;
    cout<<cnt<<endl;
    for(auto i:clr)
        cout<<m[i]<<" ";
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
    fill(v.begin(), v.end(),true);
    sieve();
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