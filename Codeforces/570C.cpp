#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll nax = 1e5 + 69;
const ll M = 1e9 + 7;
int main(){
	int n,q,res = 0;
	cin>>n>>q;
	string s;
	cin>>s;
	set<pair<int,int> > se;
	for (int i = 0; i < n; ++i)
	{
		if(s[i]!='.')
			continue;
		int start = i;
		while(i<n && s[i]=='.')
			i++;
		i--;
		res += i-start;
		se.insert({start,i});
	}
	//for(auto i : se)
	//	cout<<i.first<<' '<<i.second<<endl;
	int x = 0;
	while(q--){
		++x;
		int ind;
		char val;
		cin>>ind>>val;
		--ind;
		if(val=='.'){
			if(s[ind]=='.'){
				cout<<res<<'\n';
				continue;
			}
			s[ind] = val;
			auto it = se.lower_bound({ind,0});
			if(it==se.end()){
				//cout<<"YAHA"<<endl;
				if(!se.size()){
					se.insert({ind,ind});
					cout<<res<<'\n';
					continue;
				}
				--it;
				int fir = it->first, sec = it->second;
				if(sec!=ind-1)
					se.insert({ind,ind});
				else{
					se.erase({fir,sec});
					se.insert({fir,sec+1});
					res++;
				}
				cout<<res<<'\n';
				continue;
			}
			if(it==se.begin()){
				int st = it->first,end = it->second ;
				if(st==ind+1){
					se.erase({st,end});
					se.insert({ind,end});
					res-=(end-st);
					res+=(end-ind);
				}
				else{
					se.insert({ind,ind});
				}
				cout<<res<<'\n';
				continue;
			}
			int nxst = it->first, nxend = it->second ;
			--it;
			int prevst = it->first, prevend = it->second;
			if(prevend==ind-1 && nxst==ind+1){
				se.erase({prevst,prevend});
				se.erase({nxst,nxend});
				se.insert({prevst,nxend});
				res-= (prevend-prevst);
				res-= (nxend-nxst);
				res+=(nxend-prevst);
				cout<<res<<'\n';
				continue;
			}
			else if(nxst==ind+1){
				se.erase({nxst,nxend});
				se.insert({ind,nxend});
				res-=(nxend-nxst);
				res+=(nxend-ind);
			}
			else if(prevend==ind-1){
				se.erase({prevst,prevend});
				se.insert({prevst,ind});
				res-=(prevend-prevst);
				res+=(ind-prevst);
			}
			else
				se.insert({ind,ind});
		}
		else{
			if(s[ind]!='.'){
				cout<<res<<'\n';
				continue;
			}
			s[ind] = val;
			//cout<<ind<<endl;
			auto it = se.lower_bound({ind,0});
			if(it==se.end())
				--it;
			//cout<<it->first<<' '<<it->second<<endl;;
			if(it->first>ind){
			//	cout<<"YAHA"<<endl;
				if(it==se.begin()){
					cout<<res<<'\n';
					continue;
				}
				--it;
			}
			int st = it->first, end = it->second;
			//cout<<st<<' '<<end;
			if(st==end){
				se.erase({st,end});
				cout<<res<<'\n';
				continue;
			}
			if(ind>st && ind<end){
				se.erase({st,end});
				res-=(end-st);
				se.insert({st,ind-1});
				se.insert({ind+1,end});
				res+=(ind-1-st);
				res+=(end-ind-1);
			}
			else if(ind==end){
				se.erase({st,end});
				se.insert({st,end-1});
				res-=(end-st);
				res+=(end-1-st);
			}
			else if(ind==st){
				se.erase({st,end});
				se.insert({st+1,end});
				res-=(end-st);
				res+=(end-1-st);
			} 
		}
		cout<<res<<'\n';
	}

	return 0;
}