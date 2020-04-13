#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<bits/stdc++.h>
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
ll check(ll x){
    for (int i = 2; i*i <= x; ++i)
    {
        if(x%i==0){
            return i;
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        ll x,y,z,ans,max=0;
        for (int i = 0; i < n; ++i)
        {
            cin>>x>>y>>z;
            if((y% (x+1))==0){
                ans = y/ (x+1);
            }
            else{
                ans = y/(x+1);
            }
            ans*=z;
            if(ans>max){
                max=ans;
            }
        }
        cout<<max<<endl;
    }
    return 0 ;
}
