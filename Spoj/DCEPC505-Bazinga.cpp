#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<vector>
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define ll long long 
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define M 10000007
using namespace std;
int main(){
    ll t,a=15000000;
    vector<ll> v(a,0);
    vector<ll> x,ans;
    v[0]=1;
    v[1]=1;
    x.emplace_back(2);
    for (int i = 4; i <= a; i+=2)
    {
        v[i]=2;
    }
    for (ll i = 3; i <=a; i+=2)
    {
        if (v[i]==0)
        {
            x.emplace_back(i);
            for (ll j = i*i; j <=a; j+=i)
                v[j]=i;
        }
    }
    ll i=5;
    while(ans.size()<2000000 ){
        if(v[i] && i!= v[i]*v[i] && !v[v[i]]&& !v[i/v[i]]){
          //  cout<<i<<endl;
            ans.eb(i);
        }
        i++;
    }
    cin>>t;
    while(t--){
        cin>>a;
        cout<<ans[a-1]<<endl;
    }
    return 0;
}