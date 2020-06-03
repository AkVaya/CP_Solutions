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
const ll M =1e8;
const ll nax=1<<20 +1 ;
ll pref[nax][2]; // pref of xor till i and even positions if j=0
void solve(){
    ll n ;
    cin>>n;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    ll curr=0,ans=0;
    pref[0][1]=1;
    for (int i = 0; i < n; ++i)
    {
        curr^=a[i];
        ans+=pref[curr][i%2]; // adding first as 1 + 2 +3 .. n-1 == n(n-1)/2 == nC2 so Yeah! 
        pref[curr][i%2]++;
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
    //cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
    //cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}