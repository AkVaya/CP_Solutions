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
const ll M =1e18;
const ll nax=1e2+1;
void solve(){
    ll n,p,k;
    cin>>n>>p>>k;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    ll tillnow=0,ans=0;
    for (int i = 0; i < k; ++i)
    {
        ll count=i;
        ll sum=tillnow;
        if(sum>p)
            break;
        for (int j = i+k-1; j < n; j+=k)
        {
            if(sum+a[j]<=p){
                sum+=a[j];
                count+=k;
                //p-=a[j];
            }
            else
                break;
        }
        ans=max(ans,count);
        tillnow+=a[i];
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
   // cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
   // cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}