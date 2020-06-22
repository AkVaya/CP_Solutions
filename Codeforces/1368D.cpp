#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<stdio.h>
#include<iomanip>
#include<bitset>
#include<algorithm>
#include<map>
#include<math.h>
#include<string>
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
const ll nax=2e6+10;
void solve(){
    ll n;
    cin>>n;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    sort(a,a+n,greater<int> ());
    vector<bitset<21> > v;
    for (int i = 0; i < n; ++i)
    {
        v.pb(bitset<21> (a[i]));
    }
    //for (int i = 0; i < v.size(); ++i)
    //{
    //    cout<<v[i]<<" "<<v[i].to_ullong()<<endl;
    //}
    for (int i = 0; i < 21; ++i)
    {
        ll cnt=0;
        for(auto j : v){
            if(j[i])
                cnt++;
        }
        //cout<<i<<" "<<cnt<<endl;
        for (int j = v.size()-1; j >= 0; --j)
        {
            if(cnt){
                v[j][i]=1;
                cnt--;
            }
            else
                v[j][i]=0;
            
        }   
    }
    ll ans=0;
    for (auto i : v)
    {
        //cout<<i.to_ullong();
        ans+=((i.to_ullong())*(i.to_ullong()));
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