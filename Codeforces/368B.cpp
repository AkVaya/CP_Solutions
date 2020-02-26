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
#define M 1000000000
using namespace std;
bool sortinrev(const pair<int,int> &a,  
               const pair<int,int> &b) 
{ 
       return (a.first > b.first); 
} 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll a[n],ans[n];
    set<ll> s;
    for (int i = 0; i < n; ++i)
    {        
        cin>>a[i];
    }
    for (int i = n-1; i >=0; --i)
    {        
        s.ins(a[i]);
        ans[i]=s.size();
    }
    while(m--){
        cin>>a[0];
        cout<<ans[a[0]-1]<<endl;
    }
    
    return 0;
}