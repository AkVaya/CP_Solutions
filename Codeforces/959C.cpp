#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int n;
	cin>>n;
	if(n<=5){
		cout<<"-1\n";
	}
	else{
		cout<<"1 2\n2 3\n2 4\n";
		for (int i = 5; i <= n; ++i)
		{
			cout<<1<<' '<<i<<'\n';
		}
	}
	for (int i = 2; i <= n; ++i)
	{
		cout<<1<<' '<<i<<'\n';
	}
	return 0;
}   