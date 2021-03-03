#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int a[n][m],b[n][m];
    int lcm1 = -1,lcm2 = -1;
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < m; ++j)
    		cin>>a[i][j];
    int lcm = 2;
    for (int i = 3; i <= 16; ++i)
    	lcm = (lcm*i)/__gcd(lcm,i);
    for (int i = 0; i < n; ++i){
    	for (int j = 0; j < m; ++j){
    		if((i+j)%2)
    			cout<<lcm<<' '; 
    		else{
    			int val1 = lcm + a[i][j]*a[i][j]*a[i][j]*a[i][j];
    			if(val1>1e6)
    				val1 = lcm - a[i][j]*a[i][j]*a[i][j]*a[i][j];
    			cout<<val1<<' ';
    		}
    	}
    	cout<<endl;
    }
    return 0;
}