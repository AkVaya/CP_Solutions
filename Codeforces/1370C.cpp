#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<stdio.h>
#include<iomanip>
#include<bitset>
#include<algorithm>
#include<map>
#include<math.h>
#include<cstring>
#include<string>
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
vector<vector<ll> > v;
vector<bool> vis;
void solve(){
    ll n;
    cin>>n;
    if(n==1){
        cout<<"FastestFinger"<<endl;
        return;
    }
    else if(n==2 || n%2){
        cout<<"Ashishgup"<<endl;
        return;
    }
    if(n%2==0){
        ll cnt=0;
        while(n%2==0){
            cnt++;
            n/=2;
        }
        if(n==1){
            cout<<"FastestFinger"<<endl;
            return;
        }
        else{
            ll x=0;
            for (int i = 3; i <= sqrt(n); i+=2)
            {
                if(n%i==0){
                    while(n%i==0){
                        n/=i;
                        x++;
                    }
                }
            }
            if(n)
                x++;
            if(cnt>=2){
                cout<<"Ashishgup"<<endl;
                return;
            }
            else{
                if(x==1){
                    cout<<"FastestFinger"<<endl;
                    return;
                }
                else{
                    cout<<"Ashishgup"<<endl;
                    return;
                }
            }
        }
    }
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
    //cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
    //cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}