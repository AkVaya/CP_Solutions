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
int main(){
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        ll check=0;
        map<ll,ll> m;
        ll b[n],a[2*n],j;
        for (int i = 0; i < n; ++i)
        {
            cin>>b[i];
            m[b[i]]=1;
            if(b[i]>=2*n)
                check=1;
        }
        ll c[2*n]={0};
        for (int i = 0; i < n; ++i)
        {
            a[2*i]=b[i];
            j=b[i]+1;
            while(m[j])
                j++;
            a[2*i+1]=j;
            m[j]=1;
            if(j>2*n)
                check=1;
            
        }
        /*for (int i = 0; i < 2*n; ++i)
        {
            cout<<a[i]<<" ";
        }
        
        for (int i = 0; i < 2*n; ++i)
        {
            if(m[i]==0){
              check=1;
              break;
            }
        }*/
        if(check){
            cout<<-1<<endl;
            continue;
        }
        else{
            for (int i = 0; i < 2*n; ++i)
            {
                cout<<a[i]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}