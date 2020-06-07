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
    ll n,x,y;
    cin>>n;
    ll num[n],cost[n];
    vector<pair<ll,ll> > ans,seats;
    vector<pair<pair<ll,ll>,ll > > v;
    for (int i = 0; i < n; ++i)
    {
        cin>>num[i]>>cost[i];
        v.pb(mp(mp(num[i],cost[i]),i));
    } 
    ll k;
    cin>>k;    
    for (int i = 0; i < k; ++i)
    {
        cin>>x;
        seats.pb(mp(x,i));
    }
    ll totalMoney=0,total=0;
    set<pair<pair<ll,ll>,ll > > s;
    sort(seats.begin(), seats.end());
    sort(v.begin(), v.end());
    for (int i = 0; i < seats.size(); ++i)
    {
        ll mx1=0,mx2=0,mx3=0;
        for (int j = 0; j < v.size(); ++j)
        {
            if(v[j].first.first>seats[i].first){
                //cout<<v[j].first.first<<endl;
                break;
            }
            else if(mx2<v[j].first.second && s.find(mp(mp(v[j].first.second,v[j].second),v[j].first.first))==s.end()){
                mx2=v[j].first.second;
                mx1=v[j].first.first;
                mx3=v[j].second;
            }
        }
        if(mx2){
            s.insert(mp(mp(mx2,mx3),mx1));
            ans.pb(mp(mx3+1,seats[i].second+1));
            total++;
            totalMoney+=mx2;
        }
    }
    cout<<total<<" "<<totalMoney<<endl;
    for (int i = 0; i < ans.size(); ++i)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
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