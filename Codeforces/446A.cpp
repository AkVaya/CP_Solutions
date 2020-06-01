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
const ll nax=1e5+1;
void solve(){
    ll n;
    cin>>n;
    ll a[n],startingfrom[n],endingon[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        startingfrom[i]=1;
        endingon[i]=1;
    }
    //cout<<endingon[0]<<" ";
    for (int i = 1; i < n; ++i)
    {
        if(a[i]>a[i-1])
            endingon[i]=1+endingon[i-1];
        else
            endingon[i]=1;
      //  cout<<endingon[i]<<" ";
    }
    //cout<<endl;
    for (int i = n-2; i >= 0; --i)
    {
        if(a[i]<a[i+1])
            startingfrom[i]=1+startingfrom[i+1];
        else
            startingfrom[i]=1;
       // cout<<startingfrom[i]<<" ";
    }
    //cout<<startingfrom[n-1]<<" ";
    //for (int i = 0; i < n; ++i)
    //{
    //    cout<<startingfrom[i]<<" ";
    //}
    //cout<<endl;
    ll ans=1;
    if(n>1)
        ans=max(ans,startingfrom[1]+1);
    for (int i = 1; i < n-1; ++i)
    {
        if(a[i-1]<a[i+1]-1)
            ans=max(ans,endingon[i-1]+startingfrom[i+1]+1);
        else
            ans=max3(ans,endingon[i]+1,startingfrom[i+1]+1);
    }
    ans=max(ans,endingon[n-1]);
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