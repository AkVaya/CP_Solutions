#include<bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
/*
A =	[1 1
	 1 0]                  
A^n = [ Fn+1 Fn
		Fn Fn-1 ] 
*/
void mult(long long a[][2],long long b[][2]){
	long long res[2][2] = {0,0,0,0};
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				res[i][j] = (res[i][j]+a[i][k]*b[k][j])%M;
			}
		}
	}
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			a[i][j] = res[i][j];
		}
	}
}
long long Fib(long long n){
	long long a[2][2] = {1,1,1,0} , b[2][2] = {1,0,0,1};
	while(n){
		if(n&1)
			mult(b,a);
		mult(a,a);
		n>>=1;
	}
	return b[0][1];
}
int main(){
	long long t,a,b,fib2,fib1;
	cin>>t;
	while(t--){
		cin>>a>>b;
		fib2 = Fib(b+2);
		fib1 = Fib(a+1);
		cout<<(fib2 - fib1 +M)%M<<'\n';
	}
}