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
const ll nax=501;
void solve(){
    ll n, m;
    cin>>n>>m;
    ll a[n][m];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>a[i][j];
        }
    }
    ll curr=0;
    for (int i = 0; i < n; ++i)
    {
        curr^=a[i][0];
    }
    if(curr){
        cout<<"TAK"<<endl;
        for (int i = 0; i < n; ++i)
        {
            cout<<1<<" ";
        }
    }
    else{
        vector<ll> v1(n,1);
        bool check=false;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if(a[i][j]!=a[i][0]){
                    v1[i]=j+1;
                    check=true;
                    break;
                }
            }
            if(check)
                break;
        }
        if(check){
            cout<<"TAK"<<endl;
            for (auto i: v1)
            {
                cout<<i<<" ";
            }
        }
        else
            cout<<"NIE"<<endl;
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