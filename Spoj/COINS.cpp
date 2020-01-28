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
map<ll,ll> m ;
ll fun(int i){
    if(m[i])
        return m[i];
    else if(i >(i/2+i/3+i/4)){
        m[i]= i ;
        return i;
    }
    else{
        m[i]= (fun(i/2)+fun(i/3)+fun(i/4));
        return m[i];
    }
}
int main()
{
    ll t,n,x,ans;
    while(cin>>t){
        m.clear();
        if(t==0)
            cout<<0<<endl;
        else
            cout<<fun(t)<<endl;
    }
    return 0;
} 