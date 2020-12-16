#include<bits/stdc++.h>
using namespace std;
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};
bool vis[11][11];
int ans=0;
bool is(int x,int y){
	return (x>=1 && x<=10 && y>=1 && y<=10);
}
void dfs(int i,int j,int moves){
	if(moves==0){
		vis[i][j]=true;
		return;
	}
	int curr = 0;
	for (int a = 0; a < 8; ++a)
	{
		if(is(i+dx[a],j+dy[a])){
			dfs(i+dx[a],j+dy[a],moves-1);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int i,j,moves;
	cin>>i>>j>>moves;
	dfs(i,j,moves);
	for (int i = 1; i <= 10; ++i)
	{
		for (int j = 1; j <= 10; ++j)
		{
			ans+=vis[i][j];
		}	
	}
	cout<<ans<<endl;
	return 0;
}