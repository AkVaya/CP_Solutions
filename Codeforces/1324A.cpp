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
#define M 10000007
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll c,d,x,y,z,n,k,t;
    cin>>t;
    while(t--){
        cin>>n;
        ll a[n];
        ll odd=0,even=0;
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
            if(a[i]%2)
                odd++;
            else
                even++;
        }
        if(even==n || odd==n){
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0 ;
}