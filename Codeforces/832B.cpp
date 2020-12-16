#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,t;
	bool check = true;
	unordered_set<char> allowed;
	cin>>s>>t;
	int q,ind = -1;
	for(auto i : s){
		allowed.insert(i);
	}
	for (int i = 0; i < t.length(); ++i)
	{
		if(t[i]=='*'){
			ind = i;
			break;
		}
	}
	cin>>q;
	while(q--){
		cin>>s;
		if((ind==-1 && s.length()!=t.length())){
			cout<<"NO\n";
			continue;
		}
		check=true;
		if(ind==-1){
			for (int i = 0; i < s.length(); ++i)
			{
				if(t[i]!='?' && s[i]!=t[i]){
						check=false;
						break;
				}
				else{
					if(allowed.find(s[i])==allowed.end()){
						check=true;
						break;
					}
				}
			}
		}
		else{
			if(s.length()<t.length()-1){
				cout<<"NO\n";
				continue;
			}
			for (int i = 0; i < ind; ++i)
			{
				if(t[i]!='?' && s[i]!=t[i]){
					check=false;
					break;
				}
				else{
					if(t[i]=='?' && allowed.find(s[i])==allowed.end()){
						check=false;
						break;
					}
				}
			}
			auto it1=s.end(),it2=t.end();
			it1--;
			it2--;
			while(it1>=s.begin() && it2>=t.begin() && *it2!='*'){
				//cout<<*it1<<' '<<*it2<<endl;
				if(*it2!='?' && *it1!=*it2){
					check=false;
					break;
				}
				else{
					if(*it2=='?' && allowed.find(*it1)==allowed.end()){
						check=false;
						break;
					}
				}
				--it1;
				--it2;
			}
			it2 = s.begin()+ind;
			while(it2<=it1){
				if(allowed.find(*it2)!=allowed.end()){
					check=false;
					break;
				}
				it2++;
			}
		}
		//cout<<s<<' ';
		cout<<(check ? "YES\n" : "NO\n");
	}
	return 0;
}