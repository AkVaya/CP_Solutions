#include<bits/stdc++.h>
using ll = long long;
using namespace std;
int main(){
	ll s, x;
   	cin>>s>>x;
   	if(x>s || (s-x)%2){
   		cout<<0<<'\n';
   		return 0;
   	}
   	ll res = 1;
   	s = (s-x)/2;
   	for (int i = 0; i < 40; ++i)
   	{
   		if((s & (1LL<<i)) & (x & (1LL<<i))){
   			cout<<"0\n";
   			return 0;
   		}
   		else if((x & (1LL<<i)))
   			res*=2;
   	}
   	bool check = false;
   	cout<<res-(s==0 ? 2 : 0)<<'\n';


   	return 0;
}