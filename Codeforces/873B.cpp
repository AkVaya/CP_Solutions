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
using namespace std;
const ll M =1e9+7;
const ll nax=2001;
void solve(){
    ll n;
    cin>>n;
    char a[n];
    ll ans=0,cnt1[n],cnt0[n],diff[n];
    cnt1[0]=0;
    cnt0[0]=0;
    map<ll,ll> m;
    set<ll> s;
    s.ins(0);
    m[0]=-1;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        if(i && a[i]=='1'){
            cnt1[i]=cnt1[i-1]+1;
            cnt0[i]=cnt0[i-1];
        }
        else if(a[i]=='1')
            cnt1[i]=1;
        else if(i && a[i]=='0'){
            cnt0[i]=cnt0[i-1]+1;
            cnt1[i]=cnt1[i-1];
        }
        else
            cnt0[i]=1;
        diff[i]=cnt0[i]-cnt1[i];
        if(s.find(diff[i])==s.end()){
            s.insert(diff[i]);
            m[diff[i]]=i;
        }
        else{
            ans=max(ans,i-m[diff[i]]);
        }
        //cout<<diff[i]<<" "<<ans<<endl;;
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
   // cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
   // cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}