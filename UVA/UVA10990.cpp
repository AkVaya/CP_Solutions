#include<iostream>
#include<set>
#include<vector>
#include<unordered_set>
#define ll long long 
#define mp make_pair
#define pb push_back
using namespace std;
ll ans[2000001]={0};
ll SOdf[2000001]={0};
ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
} 
ll fun(ll num){
    if(SOdf[num]){
        return SOdf[num];
    }
    else{
            SOdf[num] = 1 + SOdf[phi(num)];
    }
    return SOdf[num];
}
int main(){
    ll q,x,y,z=0;
    SOdf[2]=1;
    for (int i = 2; i <= 2000000; ++i)
    {
        z+=fun(i);
        ans[i]=z;
    }
    cin>>q;
    while(q--){
        cin>>x>>y;
        cout<<ans[y]-ans[x-1]<<endl;
    }
    
    return 0;
}