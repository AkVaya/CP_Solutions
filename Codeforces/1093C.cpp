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
    ll a[n+1] , b[n+1];
    for (int i = 1; i <= n/2; ++i)
    {
        cin>>b[i];
    }
    ll mx, mn;
    a[1] = 0;
    a[n] = b[1];
    mx = a[n];
    mn = a[1];
    for (int i = 2; i <= n/2; i++) {
        if (b[i] - mn <= mx) {
            a[i] = mn;
            a[n - i + 1] = b[i] - a[i];
            mx = a[n - i + 1];
        } else {
            a[n - i + 1] = mx;
            a[i] = b[i] - a[n - i + 1];
            mn = a[i];
        }
    }
    for (int i = 1; i <=n; ++i)
    {
        cout<<a[i]<<" ";
    }
    return 0 ;
}