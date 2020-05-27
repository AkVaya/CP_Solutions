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
    string s;
    cin>>s;
    ll tillNow[26],ans=0,answer[26][26];
    memset(tillNow,0,sizeof(tillNow));
    memset(answer,0,sizeof(answer));
    for (int i = 0; i < s.length(); ++i)
    {
    	for (int j = 0; j < 26; ++j)
    	{
    		answer[j][s[i]-'a']+=tillNow[j];
    		ans=max(answer[j][s[i]-'a'],ans);
    	}
    	tillNow[s[i]-'a']++;
    	ans=max(ans,tillNow[s[i]-'a']);
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
   // cin>>t;
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