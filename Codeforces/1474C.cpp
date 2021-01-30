#include<bits/stdc++.h>
using namespace std;
const int nax = 1e3 + 69;
using ll = long long;
int n,a[2*nax];
multiset<int> s;
queue<pair<int,int> >q;
bool can(int x,int sec,bool check){
	auto it1 = s.find(x);
	auto it2 = s.find(sec);
	//cout<<x<<' '<<sec<<endl;
	while(it1==it2)
		it2++;
	if(it2==s.end()){
		return false;
	}
	if(check){
		q.push({sec,x});
	}
	s.erase(it1);
	s.erase(it2);
	if(!s.size()){

		s.insert(x);
		s.insert(sec);
		return true;
	}
	else if(s.size()==1){
		s.insert(x);
		s.insert(sec);
		return false;
	}
	auto mx = s.end();
	--mx;
	bool res = false;
	if(s.find(x-(*mx))!=s.end()){
		res = can(*mx,x-*mx,check);
	}
	s.insert(x);
	s.insert(sec);
	return res;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int mx = 0;
		for (int i = 0; i < 2*n; ++i)
		{
			cin>>a[i];
			s.insert(a[i]);
			mx = max(a[i],mx);
		}
		sort(a,a+2*n);
		auto it = s.find(mx);
		int res = -1;
		for (int i = 2*n-2; i >= 0; --i)
		{
			if(can(mx,a[i],false)){
				res = i;
				break;
			}
		}
		if(res>=0){
			cout<<"YES"<<endl;
			can(mx,a[res],true);
			pair<int,int> f = q.front();
			cout<<f.first+f.second<<'\n';
			while(q.size()){
				f = q.front();
				q.pop();
				cout<<f.first<<' '<<f.second<<'\n';
			}
		}
		else
			cout<<"NO"<<endl;
		s.clear();
	}
	return 0;
}