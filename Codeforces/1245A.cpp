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
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}
int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        if(gcd(a,b)!=1){
            cout<<"Infinite"<<endl;
        }
        else{
            cout<<"Finite"<<endl;
        }
    }
    return 0;
} 