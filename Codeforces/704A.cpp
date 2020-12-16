#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5+69;
int main(){
	int n,q,x,y,i=0,res=0,ind=0;
	cin>>n>>q;
	vector<bool> check(nax,false);
	vector<vector<int> >v(nax);
	while(q--){
		cin>>x>>y;
		if(x==1){
			v[y].push_back(ind++);
			res++;
		}
		else if(x==2){
			for(auto a : v[y]){
				if(!check[a])
					res--;
				check[a]=true;
			}
			v[y].clear();
		}
		else{
			while(i<y){
				if(!check[i]){
					check[i]=true;
					res--;
				}
				i++;
			}
		}
		cout<<res<<'\n';
	}

	return 0;
}