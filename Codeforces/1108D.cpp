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
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
#define fr(i,a,b) for (int i = a; i < b; ++i)
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=1e3+1;
void solve(){
    ll n;
    cin>>n;
    char a[n];
    ll val[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        if(a[i]=='R')
            val[i]=0;
        else if(a[i]=='G')
            val[i]=1;
        else
            val[i]=2;
    }
    ll ans=0;
    for (int i = 1; i < n; ++i)
    {
        if(val[i]==val[i-1]){
            if(i<n-1 && val[i-1]!=val[i+1]){
                val[i]=3-val[i-1]-val[i+1];

            }
            else{
                if(val[i-1]==0)
                    val[i]=1;
                else if(val[i-1]==1)
                    val[i]=2;
                else
                    val[i]=0;
            }
            ans++;
        }
    }
    cout<<ans<<endl;
    for (int i = 0; i < n; ++i)
    {
        if(val[i]==0)
            cout<<"R";
        else if(val[i]==1)
            cout<<"G";
        else
            cout<<"B";
    }
    cout<<endl;

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