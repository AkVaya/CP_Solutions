#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#include<iomanip>
#include<queue>
#define pb push_back
#define Fi first
#define Se second
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=3e5;
const ll inf=1e18;
using pii = pair<ll,ll>;
void sum(ll &a,ll b){
    a+=b;
    a%=M;
}
void solve(){
    ll p,q,r;
    cin>>p>>q>>r;
    ll a[p],b[q],c[r];
    for (int i = 0; i < p; ++i)
    {
        cin>>a[i];
    }
    for (int i = 0; i < q; ++i)
    {
        cin>>b[i];
    }
    for (int i = 0; i < r; ++i)
    {
        cin>>c[i];
    }
    sort(a,a+p);
    sort(c,c+r);
    sort(b,b+q);
    ll prefa[p+1];
    prefa[0]=0;
    for (int i = 0; i < p; ++i)
    {
        prefa[i+1]=(a[i]+prefa[i])%M;
    }
    //cout<<prefa[1]<<endl;
    ll prefc[r+1];
    prefc[0]=0;
    for (int i = 0; i < r; ++i)
    {
        prefc[i+1]=(c[i]+prefc[i])%M;
    }
    ll ans=0,temp1,temp2;
    for (int i = 0; i < q; ++i)
    {
        temp1=upper_bound(a,a+p,b[i])-a;
        temp2=upper_bound(c,c+r,b[i])-c;
        sum(ans,((b[i]*b[i]%M)*(temp1*temp2%M))%M);        
        sum(ans,(prefc[temp2]*prefa[temp1])%M);
        sum(ans,(b[i]%M*(((temp2*prefa[temp1]%M)+(temp1*prefc[temp2]%M))%M))%M);
        //cout<<ans<<endl;
    }
    cout<<ans%M<<endl;
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