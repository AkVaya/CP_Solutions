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
    ll t,n,a,b,c,min;
    cin>>t;
    while(t--){
        cin>>n>>a>>b>>c;
        ll x[n],y;
        min = 1000000000000000;
        for (int i = 0; i < n; ++i)
        {
            cin>>x[i];
            y=abs(x[i]-b)+abs(x[i]-a)+c;
            if(y<min){
                min = y ;
            }
        }
        cout<<min<<endl;

    }
    return 0 ;
}