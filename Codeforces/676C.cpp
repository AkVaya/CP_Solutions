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
const ll nax=1e2+1;
void solve(){
    ll n,k,cA=0,cB=0,check;
    cin>>n>>k;
    char a[n+1];
    vector<ll> prefa(n+1,0),prefb(n+1,0);
    for (int i = 1; i <=n; ++i)
    {
        cin>>a[i];
        cA+=(a[i]=='a');
        cB+=(a[i]=='b');
        prefa[i]+=cA;
        prefb[i]+=cB;
        //cout<<prefa[i]<<" "<<prefb[i]<<endl;
    }

    ll ind1=1,ind2=2;
    ll ans=1;
    while(ind1<=n && ind2<=n){
        check=0;
     //   cout<<"IND1: "<<ind1<<endl;
        while(ind2<=n && ((prefb[ind2]-prefb[ind1-1]<=k || prefa[ind2]-prefa[ind1-1]<=k ))){
            ans=max(ans,ind2-ind1+1);
       //     cout<<prefa[ind2]<<" "<<prefb[ind2]<<" "<<ind2<<" "<<ans<<endl;
            ind2++;
        }
        ind1++;
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