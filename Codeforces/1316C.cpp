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
    ll n,m,p;
    scanf("%lld%lld%lld",&n,&m,&p);
    ll a[n],b[m],num1,num2,check=0;
    for (ll i = 0; i < n; ++i)
    {
        scanf("%lld",&a[i]);
        if(a[i]%p && check==0){
            check=1;
            num1=i;
        }
    }
    check=0;
    for (ll i = 0; i < m; ++i)
    {
        scanf("%lld",&b[i]);
        if(b[i]%p && check==0){
            check=1;
            num2=i;
        }
    }
    cout<<num1+num2;
    return 0 ;
}
