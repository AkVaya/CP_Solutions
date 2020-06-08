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
void solve(){
    ll n;
    cin>>n;
    ll a[n+1];
    set<ll> s;
    vector<ll> v,v1;// v stores indices of 0 v1 stores values left out
    for (int i = 1; i <= n; ++i)
    {
        s.ins(i);
    }
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i+1];
        if(a[i+1])
            s.erase(a[i+1]);
        else
            v.pb(i+1);
    }
    v1.pb(*(--s.end()));
    for (set<ll>::iterator it = s.begin(); it != (--s.end()); ++it)
    {
        v1.pb(*it);
    }
    if(v1[0]==v[0]){
        swap(v1[0],v1[1]);
    }
    for (int i = 1; i < v1.size(); ++i)
    {
        if(v1[i]==v[i])
            swap(v1[i],v1[i-1]);
    }
    ll ind=0;
    for (int i = 1; i <= n; ++i)
    {
        if(a[i])
            cout<<a[i]<<" ";
        else
            cout<<v1[ind++]<<" ";
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