#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#include<queue>
#define pb push_back
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define fr(i,a,b) for (int i = a; i < b; ++i)
#define min3(a,b,c) min(c,min(a,b))
using namespace std;
typedef long long ll ;
const ll M =1e9+7;
const ll nax=1e5+5;
const ll inf=1e18;
using pii = pair<ll,ll>; 
void solve(){
    ll n,k,d;
    cin>>n>>k>>d;
    vector<vector<ll> > cnt(n+1,vector<ll>(2,0));
    cnt[0][0]=1;cnt[0][1]=0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            if(i-j>=0){
                if(j<d){
                    cnt[i][0]+=(cnt[i-j][0])%M;
                    if(cnt[i-j][1])
                        cnt[i][1]+=(cnt[i-j][1])%M;
                }
                else{
                    cnt[i][1]+=(cnt[i-j][0])%M;
                    cnt[i][1]+=(cnt[i-j][1])%M;
                }
                cnt[i][0]%=M;
                cnt[i][1]%=M;
            }
            else
                break;
            //cout<<cnt[i][0]<< " "<<cnt[i][1]<<endl;
        }
    }
    //for (int i = 1; i <= n; ++i)
    //{
    //    cout<<cnt[i][0]<<" "<<cnt[i][1]<<endl;
    //}
    cout<<cnt[n][1]%M<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //#ifndef ONLINE_JUDGE 
      //  freopen("input.txt", "r", stdin); 
      //  freopen("output.txt", "w", stdout); 
    //#endif 

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