#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x,res=0;
	cin>>n;
	vector<int> fir,sec;
	cin>>n;
	while(n--){
		cin>>x;
		fir.push_back(x);
	}
	cin>>n;
	while(n--){
		cin>>x;
		sec.push_back(x);
	}
	set<pair<vector<int>,vector<int> > > s;
	while(fir.size() && sec.size()){
		if(s.find(make_pair(fir,sec))!=s.end()){
			cout<<-1<<'\n';
			return 0;
		}
		s.insert(make_pair(fir,sec));
		int a = fir[0];
		fir.erase(fir.begin());
		int b = sec[0];
		sec.erase(sec.begin());
		if(a>b){
			fir.push_back(b);
			fir.push_back(a);
		}
		else{
			sec.push_back(a);
			sec.push_back(b);
		}
		res++;
	}
	if(fir.size())
		cout<<res<<' '<<1<<'\n';
	else
		cout<<res<<' '<<2<<'\n';

	return 0;
}