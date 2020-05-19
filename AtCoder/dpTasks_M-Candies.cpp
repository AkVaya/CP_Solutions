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
#define ll long long
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 1e9+7
#define inf 1000000000000000000
using namespace std;
void add(int& a,int b){
    a+=b;
    if(a>=M)
        a-=M;
}
void sub(int& a,int b){
    a-=b;
    if(a<0)
        a+=M;
}
void solve(){
    ll n , k;
    cin>>n>>k;
    vector<int> dp(k+1,0);
    dp[0]=1;
    for (int i = 0; i < n; ++i)
    {
        ll maxVal;
        cin>>maxVal;
        vector<int> store(k+1);
        for (int usedTillNow = k; usedTillNow>=0;--usedTillNow)
        {
            int upperLimit=usedTillNow+min(k-usedTillNow,maxVal);
            int lowerLimit=usedTillNow+1;
            int temp=dp[usedTillNow];
            if(lowerLimit<=upperLimit)
                add(store[lowerLimit],temp);
            if(upperLimit<=k-1)
                sub(store[upperLimit+1],temp);
        }
        int prefix=0;
        for (int j = 0; j<=k; ++j)
        {
            add(prefix,store[j]);
            add(dp[j],prefix);
        }
    }
    cout<<dp[k]<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
    //cin>>t;
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    return 0 ;
}