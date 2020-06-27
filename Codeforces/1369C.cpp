#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#include<queue>
#define pb push_back
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=1e5+5;
const ll inf=1e18;
using pii = pair<ll,ll>;
void solve(){
    ll k,n;
    cin>>n>>k;
    ll a[n],w[k];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    for (int i = 0; i < k; ++i)
    {
        cin>>w[i];
    }
    sort(w,w+k);
    sort(a,a+n,greater<int>());
    ll ind1=0,ind2=n-1,ans=0,x=0;
    while(w[x]==1 && x<k){
        ans+=2*a[ind1++];
        x++;
    }
    for (int i = k-1; i >= x; --i)
    {
        ans+=a[ind1];
        ind1++;
        ans+=a[ind2];
        ind2-=(w[i]-1);
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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