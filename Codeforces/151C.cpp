#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long num,div=-1;
	cin>>num;
	for (int i = 2; i <= sqrt(num); ++i)
	{
		if(num%i==0){
			div=num/i;
			break;
		}
	}
	if(div==-1){
		cout<<"1\n0\n";
	}
	else{
		long long res=-1;
		for (int i = 2; i <= sqrt(div); ++i)
		{
			if(div%i==0){
				res=div/i;
				break;
			}	
		}
		if(res==-1)
			cout<<2<<'\n';
		else
			cout<<1<<'\n'<<num/res<<'\n';
	}
    return 0;
}   