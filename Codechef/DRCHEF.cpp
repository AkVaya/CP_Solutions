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
#define Fir first
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
const ll M =1e8;
const ll nax=3e5;
const ll inf=9e18;
using pii = pair<ll,ll>;
void solve(){
    ll n,x;
    cin>>n>>x;
    ll a[n],countFromHere[n];
    ll ans=inf;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        countFromHere[i]=0;
    }
    sort(a,a+n);
    for (int i = n-2; i >=0; --i)
    {
        ll tempx=a[i];
        while(tempx<a[i+1])
            tempx*=2,countFromHere[i]++;
        if(!countFromHere[i])
            countFromHere[i]=1;
        countFromHere[i]+=countFromHere[i+1];
    }
    for (int i = 0; i < n; ++i)
    {
        ll tempx=x,curr=1;
        while(tempx<a[i])
            tempx*=2,curr++;
        if(ans>=i+curr+countFromHere[i])
            ans=i+curr+countFromHere[i];
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