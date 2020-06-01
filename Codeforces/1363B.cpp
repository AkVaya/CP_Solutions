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
    string s;
    cin>>s;
    ll c0=0,c1=0,diff1=0,diff2=0,tillnow[s.length()-1][2]={0},ans=inf;
    for (int i = 0; i < s.length(); ++i)
    {
        c0+=(s[i]=='0');
        c1+=(s[i]=='1');
    }
    for (int i = 0; i < s.length(); ++i)
    {
        if(i){
            tillnow[i][0]=tillnow[i-1][0];
            tillnow[i][1]=tillnow[i-1][1];
        }
        tillnow[i][0]+=s[i]=='0';
        tillnow[i][1]+=s[i]=='1';
        diff1=(tillnow[i][1]+c0-tillnow[i][0]);//000011
        diff2=(tillnow[i][0]+c1-tillnow[i][1]);//110000
        ans=min3(ans,diff1,diff2);
        //cout<<diff1<<" "<<diff2<<endl;
    }
    cout<<ans<<endl;
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
   // cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
   // cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}