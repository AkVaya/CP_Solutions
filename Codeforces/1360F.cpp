#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<map>
#include<math.h>
#include<unordered_map>
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
    ll n,m;
    cin>>n>>m;
    string s[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>s[i];
    }
    string ans=s[0];
    bool check=false;
    for (int j = 0; j < m; ++j)
    {
        char temp=ans[j];
        for (int k = 0; k < 26; ++k)
        {
            char x=k+'a';
            ans[j]=x;
            check=true;
            for (int i = 0; i < n; ++i)
            {
                ll count=0;
                for (int l = 0; l < m; ++l)
                {
                    if(ans[l]!=s[i][l])
                        count++;
                }
                if(count>1){
                    check=false;
                    break;
                }
            }
            if(check){
                cout<<ans<<endl;
                return;
            }
        }
        ans[j]=temp;
    }
    cout<<-1<<endl;
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