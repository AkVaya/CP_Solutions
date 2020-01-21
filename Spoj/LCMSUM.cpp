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
ll phi[1000001], ans[1000001]; 
void ETF() 
{ 
    for (ll i = 1; i <= 1000000; i++) { 
        phi[i] = i; 
        ans[i]=0;
    } 
  
    for (ll i = 2; i <= 1000000; i++) { 
        if (phi[i] == i) { 
            phi[i] = i - 1; 
            for (ll j = 2 * i; j <= 1000000; j += i) { 
                phi[j] = (phi[j] * (i - 1)) / i; 
            } 
        } 
    } 
}
void LcmSum() 
{ 
    ETF(); 
    for (ll i = 1; i <= 1000000; i++) {  
        for (ll j = i; j <= 1000000; j += i) { 
            ans[j] += (i * phi[i]); 
        } 
    }
} 
  
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n ,q,x,a,b;
    scanf("%lld",&q);
    LcmSum();
    while(q--){
        scanf("%lld",&n);
        printf("%lld\n",((ans[n]+1)*n)/2);
    }
    return 0 ;
}
