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
    ll x,y,k;
    cin>>x>>y>>k;
    if(x==y){
        if(k<x)
            cout<<-1<<endl;
        else{
            k-=x;
            if(k%2 )
                cout<<k+x-2<<endl;
            else
                cout<<k+x<<endl;
        }
    }
    else{
        ll mn=min(x,y);
        x-=mn;
        y-=mn;
        k-=mn;
        if(k<x+y)
            cout<<-1<<endl;
        else{
            if(y){
                x=y;
                y=0;
            }
            if(x%2)
                cout<<k+mn-1<<endl;
            else{
                if(k%2==0)
                    cout<<k+mn<<endl;
                else
                    cout<<k+mn-2<<endl;
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