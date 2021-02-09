#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll nax = 1e5 + 69; 
ll a[nax];
int n;
int get(int i){
    if(i==0 || i==n+1)
        return INT_MAX;
    int res;
    cout<<"? "<<i<<endl;
    cin>>res;
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    if(n==1){
        cout<<"! 1"<<endl;
    }
    else{
        int l = 1, r = n;
        cout<<"? "<<l<<endl;
        cin>>a[1];
        cout<<"? "<<r<<endl;
        cin>>a[n];
        while(l<=r){
            int mid = (l+r)/2;
            int lval = get(mid-1);
            int val = get(mid);
            int rval = get(mid+1);
            if(val<lval && val<rval){
                cout<<"! "<<mid<<endl;
                break;
            }
            else if(lval>val){
                l = mid + 1;
            }
            else r = mid - 1;
        }
    }
    return 0;
}