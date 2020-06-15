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
const ll nax=1e5+1;
void solve(){
    ll n;
    cin>>n;
    char a[n];
    ll x[2]={0,0},y[2]={0,0};// x:rbr y:brb // 0 is r
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        if(i%2){
            if(a[i]=='r')
                x[0]++;
            else
                y[1]++;
        }
        else{
            if(a[i]=='r')
                y[0]++;
            else
                x[1]++;
        }
    }
    cout<<min(max(x[0],x[1]),max(y[0],y[1]))<<endl;
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