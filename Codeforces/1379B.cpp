#include<bits/stdc++.h>
using namespace std;
const long long nax = 1e5 + 69 ;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long t,l,r,m;
    cin>>t;
    while(t--){
    	cin>>l>>r>>m;
    	long long a,b,c;
    	for (long long i = l; i <= r; ++i)
    	{
    		long long first = m/i;
    		long long diff1 = m - first*i;
    		long long second = first + 1;
    		long long diff2 = second*i - m;
    		if(l+diff1<=r){
    			if((m-diff1)/i>0){
    				a = i;
    				b = l + diff1;
    				c = l;
    				break; 
    			}
    		}
    		if(l+diff2<=r){
    			if((m+diff2)/i>0){
    				a = i;
    				b = l;
    				c = l+diff2;
    				break; 
    			}
    		}
    	}
    	cout<<a<<' '<<b<<' '<<c<<'\n';
    }
    return 0;
}