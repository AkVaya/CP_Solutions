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
using namespace std;
const ll M =1e9+7;
const ll nax=2001;
void solve(){
    string s,temp="";
    cin>>s;
    ll n=s.length();
    ll ans=1;    
    for (int i = 0; i < n; ++i)
    {
        if(s[i]=='a' || s[i]=='b'){
            temp+=s[i];
        }
    }
    for (int i = 0; i < temp.size(); ++i)
    {
        ll count=0,check=0;
        while(temp[i]=='a'){
            count++;
            check=1;
            i++;
        }
        if(check)
            i--;
        ans=(ans*(1+count%M)%M)%M;
    }
    ans--;
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
   // cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
   // cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}