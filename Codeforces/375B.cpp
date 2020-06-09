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
#define pf push_front
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
#define fr(i,a,b) for (int i = a; i < b; ++i)
using namespace std;
const ll M =1e9+7;
const ll nax=5e3+1;
void solve(){
    ll n,m;
    cin>>n>>m;
    char a[n][m];
    ll count[n][m];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>a[i][j];
            count[i][j]=0;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if(j){
                count[i][j]=count[i][j-1];
                if(a[i][j]=='1')
                    count[i][j]++;
                else
                    count[i][j]=0;
            }
            else
                count[i][j]=a[i][j]=='1';
            //cout<<count[i][j]<<" ";
        }
        //cout<<endl;
    }
    ll ans=0;
    for (int j = 0; j < m; ++j)
    {
        ll temp[n];
        for (int i = 0; i < n; ++i)
        {
            temp[i]=count[i][j];
        }
        sort(temp,temp+n);
        for (int i = 0; i < n; ++i)
        {
            //cout<<temp[i]<<" ";
            ans=max(ans,temp[i]*(n-i));
        }
        //cout<<endl;
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