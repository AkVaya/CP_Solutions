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
#define fi first
#define se second
#define ll long long 
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 10000007
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    ll a[n],minodd=10000000000,ans=0;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        ans+=a[i];
        if(a[i]%2 && minodd>a[i]){
            minodd=a[i];
        }
    }
    if(ans%2){
        cout<<ans-minodd;
    }
    else{
        cout<<ans;
    }
    return 0 ;
}