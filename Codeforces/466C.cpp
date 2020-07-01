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
const ll M =1e8;
const ll nax=1e2+5;
const ll inf=1e18;
using pii = pair<ll,ll>;
void solve(){
    ll n;
    cin>>n;
    ll a[n],total=0,ans=0;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        total+=a[i];
    }
    if(total%3){
        cout<<0<<endl;
        return;
    }
    vector<ll> numfrom(n,0);
    ll sum=0;
    for (int i = n-1; i >= 0; --i)
    {
        sum+=a[i];
        if(i<n-1 && sum==(total)/3)
            numfrom[i]=1+numfrom[i+1];
        else if(i<n-1)
            numfrom[i]=numfrom[i+1];
        else
            numfrom[i]=(sum==total/3); 
    }
    sum=0;
    for (int i = 0; i < n-2; ++i)
    {
      //  cout<<numfrom[i]<< " ";
        sum+=a[i];
        if(sum==total/3){
            ans+=numfrom[i+2];
        }
    }
    //cout<<numfrom[n-2]<<" "<<numfrom[n-1]<<endl;
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