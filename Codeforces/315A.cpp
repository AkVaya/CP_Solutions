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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    ll a[n][2],check,ans=0;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i][0]>>a[i][1];
    }
    for (int i = 0; i < n; ++i)
    {
        check=0;
        for (int j = 0; j < n; ++j)
        {
            if(i!=j && a[i][0]==a[j][1]){
                check=1;
                break;
            }
        }
        if(!check){
            ans++;
        }
    }
    cout<<ans;
    return 0 ;
}