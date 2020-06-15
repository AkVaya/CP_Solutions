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
    ll n , m;
    cin>>n>>m;
    if(n>m+1 || m>2*(n+1))
        cout<<-1<<endl;
    else{
        if(n>=m){
            while(m-- && n--)
                cout<<"01";
            if(n)
                cout<<0;
            cout<<endl;
        }
        else if(m>2*n){
            while(m>2){
                cout<<"110";
                m-=2;
            }
            while(m--)
                cout<<"1";
        }
        else{
            ll count = m-n;
            n-=count;
            while(count--)
                cout<<"110";
            while(n--)
                cout<<"10";
            cout<<endl;
        }
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