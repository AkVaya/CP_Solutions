#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<map>
#include<math.h>
#include<string.h>
#include<ctime>
#include<cmath>
#define ll long long
#define eb emplace_back
#define pb push_back
#define ins insert 
#define mp make_pair
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
using namespace std;
void solve(){
    double h,c,temp;
    cin>>h>>c>>temp;
    ll ans=1;
    double l=1,r=1e10,x=inf;
    if(temp<=(h+c)/2){
    	cout<<2<<endl;
    	return ; 
    }
    //cout<<r<<endl;
    double curr2=h;
    ll count=0;
    while(l<=r ){
    	ll mid=(l+r)/2;
    	double curr1=double(mid*h + (mid-1)*c)/double(2*mid-1);
    	if(abs(temp-curr1)<abs(curr2-temp)){
    		ans=2*mid-1;
    		curr2=curr1;
    	}
    	else if(abs(temp-curr1)==abs(curr2-temp)){
    		if(ans>2*mid-1){
    			ans=2*mid-1;
    			curr2=curr1;
    		}
    	}
       	if(curr1>temp)
    		l=mid+1;
    	else
    		r=mid-1;
    	//cout<<l<<" "<<r<<endl;
    	//count++;
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1,t1=1;
    cin>>t;
    //clock_t t3 = clock();
    while(t--){
        //cout<<"Case #"<<t1++<<": ";        
        solve();
    }
    //clock_t t2 = clock();
   // cout << "Time-Taken: " << ((t2 - t3) / (double)CLOCKS_PER_SEC) << endl;
   // cout << CLOCKS_PER_SEC << endl;
    return 0 ;
}