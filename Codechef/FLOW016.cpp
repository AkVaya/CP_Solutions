#include<bits/stdc++.h>
using namespace std; 
#define ll long long 
#define MOD 1000000007
#define ULL unsigned long long
map<ll , ll > m;
ll fun(ll a,ll b){
    if(b==0){
        return a;
    }
    else{
        return fun(b,a%b);
    }
}
int main() 
{ 
   ULL t ,a,b,n;
   cin>>t;
   while(t--){
        cin>>a>>b;
        n = (a>b ? fun(a,b) : fun(b,a));
        cout<<n<<" "<<a*b/n<<endl;
   }
   return 0; 
} 