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
const ll nax=2e6+10;
void solve(){
    ll n;
    cin>>n;
    cout<<7+(n-1)*3<<endl;
    cout<<"0 0"<<endl;
    cout<<"0 1"<<endl;
    cout<<"1 1"<<endl;
    cout<<"1 0"<<endl;
    cout<<"2 1"<<endl;
    cout<<"1 2"<<endl;
    cout<<"2 2"<<endl;
    ll x=3,y=3;
    n--;
    while(n--){
        cout<<x<<" "<<y<<endl;
        cout<<x-1<<" "<<y<<endl;
        cout<<x<<" "<<y-1<<endl;
        x++;y++;
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