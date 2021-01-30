#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,diff,cnt = 0,t; 
	cin>>n>>diff;
	string a,b,res;
	cin>>a>>b;
	res = a;
	t = diff;
	vector<int> ind;
	for(int i = 0; i < n; ++i){
		if(a[i]!=b[i]){
			cnt++;
			ind.push_back(i);
		}
	}
	if(((cnt+1)/2)>diff){
		cout<<-1<<'\n';
		return 0;
	}
	//cout<<diff<<' '<<cnt<<endl;
	if(diff<cnt){
		//cout<<"YAHA"<<endl;
		int fir = cnt-diff;
		int i = 0;
		for(i = 0; i < ind.size() && fir>0; ++i){
			res[ind[i]] = a[ind[i]];
			fir--;
		}
		fir = cnt-diff;
		for(;fir>0; ++i){
			res[ind[i]] = b[ind[i]];
			fir--;
		}
		while(i<ind.size()){
			for (int j = 0; j < 26; ++j)
			{
				if(a[ind[i]]!=j+'a' && b[ind[i]]!=j+'a'){
					res[ind[i]] = j+'a';
					break;
				}
			}
			i++;
		}
		diff = 0;

	}
	else{
		for(auto i : ind){
			for (int j = 0; j < 26; ++j)
			{
				if(a[i]!=j+'a' && b[i]!=j+'a'){
					res[i] = j+'a';
					break;
				}
			}
		}
		diff-=cnt;
	}
	//cout<<diff<<endl;
	int i = 0,curr = 0;
	while(diff>0){
		if(curr<ind.size() && ind[curr]==i){
			curr++;
			i++;
			continue;
		}
		for (int j = 0; j < 26; ++j)
		{
			if(a[i]!=j+'a' && b[i]!=j+'a'){
				res[i] = j+'a';
				diff--;
				break;
			}
		}
		i++;
	}
	cout<<res<<endl;
	return 0;
}