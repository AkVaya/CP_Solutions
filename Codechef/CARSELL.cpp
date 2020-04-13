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
#define M 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        ll a[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        ll count=0,ans=0;
        for (int i = n-1; i >= 0; --i)
        {
            if(a[i]>0)
                a[i]-=count;
            if(a[i]<0)
                a[i]=0;
            count++;
            ans=(ans+a[i])%M; 
            //cout<<ans<<" "<<a[i]<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
} 