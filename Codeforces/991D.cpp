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
const ll M =998244353;
const ll nax=1;
ll n;
void solve(){
    string s1,s2;
    cin>>s1>>s2;
    ll ans=0;
    for(int i = 1 ; i < s1.length(); ++i){

        if(s1[i]==s1[i-1]&&s1[i]=='0'&&s2[i-1]=='0')
        {
            s1[i]=s1[i-1]=s2[i-1]='X';
            ans++;
        }
        else if(s1[i]==s1[i-1]&&s1[i]=='0'&&s2[i]=='0')
        {
            s1[i]=s1[i-1]=s2[i]='X';
            ans++;
        }
        else if(s2[i]==s2[i-1]&&s2[i]=='0'&&s1[i-1]=='0')
        {
            s2[i]=s2[i-1]=s1[i-1]='X';
            ans++;    
        }
        else if(s2[i]==s2[i-1]&&s2[i]=='0'&&s1[i]=='0')
        {
            s2[i]=s2[i-1]=s1[i]='X';
            ans++;    
        }
    }
    cout<<ans;
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