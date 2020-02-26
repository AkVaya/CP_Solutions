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
ll gcd(ll a, ll b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main(){
    ll t,a,b,greater,smaller;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&a,&b);
        greater = (a>b ? a :b );
        smaller = a+b-greater;
        if(gcd(greater, smaller)!=1){
            printf("-1\n");
        }
        else{
           printf("%lld\n",a*b-(a+b-1));
        }
    }
    return 0;
}