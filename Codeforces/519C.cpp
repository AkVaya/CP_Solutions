#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int a,b;
	cin>>a>>b;
	if(a>b)
		a = min(a,2*b);
	else 
		b = min(b,2*a);
	cout<<(a+b)/3<<'\n';
	return 0;
}