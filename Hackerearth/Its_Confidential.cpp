#include<bits/stdc++.h>
using namespace std;
string solve(string s){
	if(s.length()==0)
		return "";
	int sz = (s.length()-1)/2;
	string curr;
	curr+=s[sz];
	curr+=solve(s.substr(0,sz));
	curr+=solve(s.substr(sz+1,s.length()-sz-1)); 
	return curr;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	long long t,n;
	string s;
	cin>>t;
	while(t--){
		cin>>n>>s;
		cout<<solve(s)<<endl;
	}
	return 0;
}