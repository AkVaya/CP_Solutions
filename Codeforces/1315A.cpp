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
    ll t,a,b,x,y;
    cin>>t;
    while(t--){
        cin>>a>>b>>x>>y;
        //x++;y++;
        ll greater = max(max((b-y-1)*a,a*(y)),max((x)*b,(a-x-1)*(b)));
        cout<<greater<<endl;
    }
    return 0;
}