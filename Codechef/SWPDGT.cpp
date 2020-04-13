#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#define pb push_back
#define ins insert 
#define mp make_pair
#define ll long long 
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 10000007
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll c,d,x,y,z,n,k,t;
    cin>>t;
    while(t--){
        ll x,y,ans=0;
        cin>>x>>y;
        if(x<y){
            ll temp=x;
            x=y;
            y=temp;
        }
        if(x>=10)
        ans=max(ans,(y%10)*10 +x/10+(x%10)+(y-y%10));
        if(y>=10)
            ans=max(ans,(x%10) *10 +y/10+(y%10)+(x-x%10));
        ans=max(ans,x+y);
        cout<<ans<<endl;
    }
    return 0 ;
}
