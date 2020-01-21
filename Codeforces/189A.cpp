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
ll a, b,c;
ll x[4001]={0};
ll dp(ll n){
    if(n<0){
        return -4000;
    }
    if(x[n]){
        return x[n];
    }  
    else{
        x[n] = 1 + max3(dp(n-a),dp(n-b),dp(n-c));
    }
    return x[n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n>>a>>b>>c;
    x[0]=1;
    cout<<dp(n)-1;

	return 0 ;
}
