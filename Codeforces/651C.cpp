#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,a,b,res=0;
	cin>>n;
	map<pair<long long,long long>,long long> all;
	map<long long,long long> x,y;
	while(n--){
		cin>>a>>b;
		x[a]++;
		y[b]++;
		all[{a,b}]++;
	}
	for(auto i : x)
		res+=((i.second-1)*i.second)/2;
	for(auto i : y)
		res+=((i.second-1)*i.second)/2;
	for(auto i : all)
		res-=((i.second-1)*i.second)/2;
	cout<<res<<endl;
	return 0;
}