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
const ll nax=1e2+1;
void solve(){
    string s;
    cin>>s;
    bool dp[s.size()+1][8];
    ll ans[s.size()+1][8];
    memset(ans,-1,sizeof(ans));
    memset(dp,false,sizeof(dp));
    dp[0][(s[0]-'0')%8]=true;
    for (int i = 1; i <s.size(); ++i)
    {
        dp[i][(s[i]-'0')%8]=true;
        for (int j = 0; j < 8; ++j)
        {
            if(dp[i-1][j]){
                dp[i][(j*10+s[i]-'0')%8]=true;
                dp[i][j]=true;
                ans[i][(j*10+s[i]-'0')%8]=j;
                ans[i][j]=j;
            }
        }
    }
    for (int i = 0; i <s.size(); ++i)
    {
        if(dp[i][0]){
            cout<<"YES"<<endl;
            string out="";
            ll ind=i,j=0;
            while(1){
                if(ans[ind][j]==-1 || ans[ind][j]!=j)
                    out+=s[ind];
                if(ans[ind][j]==-1)
                    break;
                j=ans[ind][j];
                ind--;
            }
            reverse(out.begin(),out.end());
            cout<<out<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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