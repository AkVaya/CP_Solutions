#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t;
	long long x;
	cin>>t;
	while(t--){
		cin>>x;
		bool check = false;
		long long root = sqrtl(x),temp = 0;
		while(root>0){
			if(temp*temp>x)
				break;
			if(root*root + temp*temp == x){
				check = true;
				break;
			}
			else if(root*root + temp*temp < x)
				temp++;
			else
				root--;
		}
		if(check)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}