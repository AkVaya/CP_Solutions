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
ll dp[10000]={0};
ll fun(ll x,ll *a){
    if(dp[x]){
        return dp[x];
    }
    else if(x==0){
        dp[0] = a[0];
        return dp[0];
    }
    else if(x==1){
        dp[1] = max(a[0],a[1]);
        return dp[1];
    }
    else{
        dp[x] = max(fun(x-1,a),a[x] + fun(x-2 , a) );
        return dp[x];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n,q=1;
    cin>>t;
    while(t--){
        cin>>n;
        if(!n){
            cout<<"Case "<<q++<<": "<<0<<endl;
            continue;
        }
        ll a[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
            dp[i] = 0;
        }
        ll ans =fun(n-1, a);
        cout<<"Case "<<q++<<": "<<ans<<endl;
    }
	return 0 ;
}
