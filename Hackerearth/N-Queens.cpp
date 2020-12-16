#include<bits/stdc++.h>
using namespace std;
bool is_attacked(vector<vector<int> >& ans,int i,int j){
	int n = ans.size();
	for (int k = 0; k < n; ++k)
	{
		if(ans[k][j] || ans[i][k])
			return true;
	}
	int x = i+1, y = j+1;
	while(x<n && y<n)
		if(ans[x++][y++])
			return true;
	x = i+1, y = j-1;
	while(x<n && y>=0)
		if(ans[x++][y--])
			return true;
	x = i-1, y = j-1;
	while(x>=0 && y>=0)
		if(ans[x--][y--])
			return true;
	x = i-1, y = j+1;
	while(x>=0 && y<n)
		if(ans[x--][y++])
			return true;
	return false;
}
bool solve(vector<vector<int> >& ans,int i){
	if(i==ans.size())
		return true;
	for (int y = 0; y < ans.size(); ++y)
	{
		if(!is_attacked(ans,i,y)){
			ans[i][y] = 1;
			if(solve(ans,i+1))
				return true;
			ans[i][y] = 0;
		}
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	vector<vector<int> > ans(n,vector<int>(n,0));
	if(solve(ans,0)){
		for (int i = 0; i < n; ++i)
		{
			for(auto j : ans[i])
				cout<<j<<' ';
			cout<<'\n';
		}
	}
	else
		cout<<"Not possible\n";
	
	return 0;
}