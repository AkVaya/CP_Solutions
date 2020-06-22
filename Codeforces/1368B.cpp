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
    string s="codeforces";
    ll cnt[10],last=1;
    for (int i = 0; i < 10; ++i)
        cnt[i]=0;
    for (int i = 1; i <= 100; ++i)
    {
        ll temp=1;
        for (int j = 0; j < 10; ++j)
        {
            temp*=i;
            if(temp>=n)
                break;
        }
        if(temp>=n)
            break;
        last=i;
    }
    //cout<<last<<endl;
    ll temp=1;
    for (int i = 0; i < 10; ++i)
    {
        cnt[i]=last;
        temp*=last;
    }
    //cout<<temp<<endl;
    if(temp<n){
        for (int i = 0; i < 10; ++i)
        {
            temp/=last;
            temp*=(last+1);
            cnt[i]=last+1;
            //cout<<cnt[i]<<" ";
            if(temp>=n)
                break;
        }
    }
    for (int i = 0; i < s.length(); ++i)
    {
        for (int j = 0; j < cnt[i]; ++j)
        {
            cout<<s[i];
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