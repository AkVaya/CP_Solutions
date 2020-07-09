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
ll fun(ll a){
    ll x=0;
    while(a>0){
        x+=a%10;
        a/=10;
    }
    return x;
}
void solve(){
    ll n;
    cin>>n;
    ll cnt1=0,cnt2=0,x,y;
    for (int i = 0; i < n; ++i)
    {
        cin>>x>>y;
        ll temp1=fun(x),temp2=fun(y);
        if(temp1>temp2)
            cnt1++;
        else if(temp1<temp2)
            cnt2++;
        else
            cnt1++,cnt2++;
    }
    if(cnt1>cnt2)
        cout<<0<<" "<<cnt1<<endl;
    else if(cnt1<cnt2)
        cout<<1<<" "<<cnt2<<endl;
    else
        cout<<2<<" "<<cnt1<<endl;
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