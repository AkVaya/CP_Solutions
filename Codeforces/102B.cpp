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
ll fun(ll a){
    ll b=0;
    while(a!=0){
        b+=(a%10);
        a/=10;
    }
    return b;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a,b,c,d,x,y,z,n,k;
    string s;
    cin>>s;
    ll ans=(s.length()>1 ? 1 : 0) , num=0;
    for (int i = 0; i < s.length(); ++i)
    {
        num+=(s[i]-'0');
    }
    while(num>=10){
        ans++;
        num = fun(num);
    }
    cout<<ans;
    return 0 ;
}