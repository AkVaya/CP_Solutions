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
#define M 1000000000000
using namespace std;
int main(){
    ll t,n,m,x;
    cin>>t;
    while(t--){
        cin>>n>>m;
        bool check=true;
        ll a[n],b[m];
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
        }
        for (int i = 0; i < m; ++i)
        {
            cin>>b[i];
            b[i]--;
        }
        for(int i=0;i<n;i++){
        for (int j = 0; j < m; ++j)
       {
                if(b[j]<n && a[b[j]]>a[1+b[j]]){
                    x = a[b[j]];
                    a[b[j]]=a[1+b[j]];
                    a[1+b[j]]=x;
                }
        }}
        for (int i = 0; i < n-1; ++i)
        {
            if(a[i]>a[i+1]){
                check=false;
                break;
            }
        }
        if(check)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}