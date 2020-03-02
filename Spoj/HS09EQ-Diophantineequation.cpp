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
    ll t,n,diff,ans;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        ans=0;
        for(ll i=0;i*i*i<=n;i++){
            for(ll j=0;j*j*j*j<=n;j++){
                diff = n - i*i*i - j*j*j*j;
                if(diff>=0){
                    ans+=sqrt(diff)+1;
                }
            }
        }
        printf("%lld\n",ans);
    }

    return 0;
}