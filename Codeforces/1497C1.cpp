#include<bits/stdc++.h> 
using namespace std; 
const int nax = 5e6 + 69;
int a[nax];
int m[nax][2];
int main() 
{ 
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if(n==4){
			cout<<"1 1 2\n";
			continue;
		}
		if(n%3==0){
			cout<<n/3<<' '<<n/3<<' '<<n/3<<'\n';
			continue;
		}
		if(n%2){
			cout<<n/2<<' '<<n/2<<' '<<1<<'\n';
		}
		else{
			int x = n/2;
			int y = n-x;
			if(y%2==0 && x%2==0){
				cout<<x<<' '<<y/2<<' '<<y/2<<'\n';
			}
			else{	
				if(x%2)
					x--;
				cout<<x<<' '<<x<<' '<<2<<'\n';
			}
		}
	}
	return 0; 
} 