#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    int t;
    cin>>t;
    while(t--){
    	int a,b;
    	cin>>a>>b;
    	int res = INT_MAX,i = 0,val = 0;
    	if(b==1)
    		val = b++;
    	while(i<35){
    		int temp = b + i,x = a,curr=val+i;
    		while(x){
    			x/=temp;
    			curr++;
    		}
    		res = min(res,curr);
    		i++;
    	}
    	cout<<res<<'\n';
    }
    return 0;
}