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
    ll n,k;
    cin>>n>>k;
    char a[n];
    string REQ="RGB";
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    ll ans=M;
    for (ll comb = 0; comb < 3; ++comb)
    {
        ll store[n],curr=0;
        for (int i = 0; i < n; ++i)
        {
            if(a[i]==REQ[(i+comb)%3])
                store[i]=0;
            else
                store[i]=1;
            curr+=store[i];
            if(i>=k)
                curr-=store[i-k];
            if(i>=k-1)
                ans=min(ans,curr);

        }
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