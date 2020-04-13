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
    ll t;
    cin>>t;
    while(t--){
        ll n,x=0,y=0;
        cin>>n;
        ll a[n],max=0;
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
            if(a[i]>max){
                max=a[i];
                x=i;
            }
        }
        for (int i = n-1; i >= 0; --i)
        {
            if(a[i]==max){
                y=i;
                break;
            }
        }
        if(y+n/2-x>n-1)
            cout<<0<<endl;
        else{
            y+=n/2-x;
            max=0;
            while(y<n){
                max++;
                y++;
            }
            cout<<max<<endl;
        }
    }
    return 0 ;
}
