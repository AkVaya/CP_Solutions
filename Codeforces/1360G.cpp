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
#define max3(a,b,c) max(c,max(a,b))
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<b;i++)
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
using namespace std;
using ll = long long;
const ll M =1e9+7;
const ll nax=2001;
void solve(){
    ll n,m,a,b;
    cin>>n>>m>>a>>b;
    float div1=(float)n/m,div2=(float)b/a;
    if(div1!=div2){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        ll x=1,y=1;
        ll ans[n+1][m+1];
        memset(ans,0,sizeof(ans));
        ll count=0;
        while(count<=a*n && x<=n){
            ll count2=0;
            while(count2<a){
                ans[x][y]=1;
                count++;count2++;
                y++;
                if(y>=m+1)
                    y-=m;
            }
            x++;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                cout<<ans[i][j];
                //cout<<i<<" "<<j<<endl;
            }
            cout<<endl;
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