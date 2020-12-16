#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	long long n;
	cin>>n;
	long long a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	if(n==1){
		cout<<1<<' '<<1<<endl<<-a[0]<<endl;
		cout<<1<<' '<<1<<endl<<0<<endl;
		cout<<1<<' '<<1<<endl<<0<<endl;
	}
	else{
		cout<<1<<' '<<1<<endl<<-a[0]<<endl;
		cout<<1<<' '<<n<<endl<<0<<' ';
		for (int i = 1; i < n; ++i)
		{
			cout<<-n*a[i]<<' ';
		}
		cout<<endl<<2<<' '<<n<<endl;
		for (int i = 1; i < n; ++i)
		{
			cout<<(n-1)*a[i]<<' ';
		}
	}

	return 0;
}   