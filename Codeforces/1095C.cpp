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
map<ll,ll> m;
queue<ll> q;
ll fun(ll x){
    ll cnt=0;
    for (int i = 0; i <= 30; ++i)
    {
        if(x & (1<<i)){
            cnt++;
            if(i)
                q.push(1<<i);
            m[(1<<i)]++;
        }
    }
    return cnt;
}
void solve(){
    ll n,k;
    cin>>n>>k;
    ll cnt=fun(n);
    //for(auto i : m){
    //    cout<<i.first<<" "<<i.second<<endl;
    //}
    if(cnt>k)
        cout<<"NO"<<endl;
    else{
        while(cnt<k && !q.empty()){
            ll x=q.front();
            q.pop();
            m[x]--;
            m[x/2]+=2;
            if(x/2>1){
                q.push(x/2);
                q.push(x/2);
            }
            cnt++;
        }
        //cout<<cnt<<endl;
        if(cnt<k)
            cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            for(auto i : m){
                for (int j = 0; j < i.second; ++j)
                {
                    cout<<i.first<< " ";
                }
            }
            cout<<endl;
        }
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