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
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    ll j=0,ans=0,curr=0,finali=0,finalj=0 ;
    for (int i = 0; i < n; ++i)
    {
        if(j<i){
            j=i;
            curr=0;
        }
        while(j<n){
            curr+=!a[j];
            if(curr>k){
                curr--;
                break;
            }
            j++;
        }
        if(ans<j-i){
            ans=j-i;
            finalj=j;
            finali=i;
        }
        if(curr)
            curr-=!a[i];
    }
    cout<<ans<<endl;
    for (int i = 0; i < finali; ++i)
    {
        cout<<a[i]<<" ";
    }
    for (int i = finali; i < finalj; ++i)
    {
        cout<<1<<" ";
    }
    for (int i = finalj; i < n; ++i)
    {
        cout<<a[i]<<" ";
    }
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