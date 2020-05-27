#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<map>
#include<math.h>
#include<unordered_map>
#include<string.h>
#include<ctime>
#include<cmath>
#define max3(a,b,c) max(c,max(a,b))
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<b;i++)
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
using namespace std;
using ll = long long;
const ll M =1e9+7;
const ll nax=200001;
void solve(){
    ll n;
    cin>>n;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    vector<vector<ll> > comb(1001,vector<ll>(1001,0));
    for (int i = 0; i < 1001; ++i)
    {
        for (int j = 0; j < 1001; ++j)
        {
            if(j==0)
                comb[i][j]=1;
            else if(j<=i){
                comb[i][j] = (comb[i-1][j]+comb[i-1][j-1])%M;
            }
            else break;
        }
    }
    ll ans=1,temp=0;
    for(int i=0;i<n;i++){
        ans=(ans*comb[temp+a[i]-1][a[i]-1])%M;
        temp+=a[i];
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