#include<bits/stdc++.h>
using namespace std;
int mn = INT_MAX;
bool check(string n,int cnt){
	int val = stoi(n);
	int sq = sqrt(val);
	if(sq*sq==val && val){
		int ind = 0;
		while(n[ind]=='0')
			cnt++,ind++;
		mn = min(mn,cnt);
		return true;
	}
	bool res=false;
	if(n.size()==1)
		return false;
	for (int i = 1; i < n.size()-1; ++i)
	{
		string x = n.substr(0,i) + n.substr(i+1,n.length()-i);
		res|=check(x,cnt+1); 
	}
	res|= check(n.substr(0,n.length()-1),cnt+1);
	res|= check(n.substr(1,n.length()-1),cnt+1);
	return res;
}
int main()
{
	int n;
	cin>>n;
	if(check(to_string(n),0))
		cout<<mn<<'\n';
	else
		cout<<"-1\n";
	return 0;
}