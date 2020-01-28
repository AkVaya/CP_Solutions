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
ll n,c;
ll *a;
ll check(ll x){
    ll cur=a[0],num=1;
    for (int i = 1; i < n; ++i)
    {
        if(a[i]-cur>=x){
            num++;
        if(num==c){
            return 1;
        }
        cur=a[i];
        }
    }
    return 0;
}
void binsearch(){
    ll mid,start=0 ,end=a[n-1],max=0;
    while(end-start>1){
        mid = (start+end)/2;
        if(check(mid)){
            start=mid;
            if(max<mid)
                max=mid;
        }
        else{
            end = mid;
        }
    }
    cout<<max<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,m, ans;
    cin>>t;
    while(t--){
        cin>>n>>c;
        a = new ll[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        binsearch();
        delete[] a;
    }
    return 0 ;
}