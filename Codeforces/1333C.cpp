#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<queue>
#include<vector>
#define pb push_back
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define Fi first
#define Se second
#define ll long long 
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
using namespace std;
const ll M =1e9+7;
const ll nax=3e5;
const ll inf=1e18;
using pii = pair<ll,ll>;
bool cmp(pii &a, pii &b){
    if(a.first!=b.first)
        return a.first<b.first;
    return a.second>b.second ;
}
void solve(){
    ll n,x;
    cin>>n;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    vector<vector<ll> > v;
    for (int i = 0; i < n; ++i)
    {
        ll j;
        vector<ll> temp;
        for (j = i; j < n; ++j)
        {
            if(a[j]!=0){
                temp.pb(a[j]);
            }
            else
                break;
        }
        i=j;
        v.pb(temp);
    }
    ll ans=0;
    for (int i = 0; i < v.size(); ++i)
    {
        map<ll,ll> m;
        ll sum=0,first=0,mx=0;
        for (int j = 0; j < v[i].size(); ++j )
        {
            sum+=v[i][j];
            //cout<<sum<<" ";
            if(sum!=0 && !m[sum]){
                ans+=j-first+1;
            }
            else{
                first=max(first,m[sum]+1);
                ans+=j-first+1;
            }
            m[sum]=j+1;
        }    
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //#ifndef ONLINE_JUDGE 
      //  freopen("input.txt", "r", stdin); 
      //  freopen("output.txt", "w", stdout); 
    //#endif 

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