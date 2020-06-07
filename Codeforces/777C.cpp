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
    ll n,m,q;
    cin>>n>>m;
    ll a[n][m],dp[n][m],final[n];// final[i] signifies the max amount of rows we can go down -1 from the ith row
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>a[i][j];
            dp[0][j]=1;
        }
        final[i]=0;
    }
    for (int i = n-1; i >= 0; --i)
    {
        for (int j = 0; j < m; ++j)
        {
            if(i==n-1)
                dp[i][j]=1;
            else if(a[i+1][j]>=a[i][j])
                dp[i][j]=dp[i+1][j]+1;
            else
                dp[i][j]=1;
            final[i]=max(final[i],dp[i][j]);
        }
    }
    /*for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cin>>q;
    while(q--){
        cin>>n>>m;
        cout<<(final[n-1]>=m-n+1 ? "Yes" : "No")<<endl;
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