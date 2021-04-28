#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
const ll M = 1e9 + 7;
int main(){
	int n;
	cin>>n;
	vector<int> cnt(nax,0);
	int a[n], res = 1;
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	map<int,int>m;
	set<int> s;
	for (int i = 0; i < n; ++i)
	{
		if(m.count(cnt[a[i]])){
			m[cnt[a[i]]]--;
			if(!m[cnt[a[i]]])
				m.erase(cnt[a[i]]);
		}
		s.insert(a[i]);
		cnt[a[i]]++;
		m[cnt[a[i]]]++;
		if(m.size()==2){
			auto fir = m.begin();
			auto sec = ++fir;
			--fir;
			if(fir->second==1 && fir->first==1)
				res = max(res,sec->second*sec->first + 1);
			if((sec->second==1)){
				if(sec->first==fir->first + 1)
					res = max(res,fir->first*(fir->second + 1) + 1);
			}
		}
		else if(m.size()==1){
			auto fir = m.begin();
			if(s.size()==1 || fir->first==1)
				res = max(res,(int)fir->second*fir->first);
		}
		//cout<<res<<endl;
		//	cout<<endl;
	} 
	cout<<res<<'\n';
	return 0;
}