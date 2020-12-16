#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	string resa="\"",resb="\"",curr="";
	bool check=false,check2=false,check3=false;
	for(auto i : s){
		if((i==',' || i==';')){
			if(!check && curr!=""){
				if(check2 && curr.size()>1){
					resb+=curr+",";
					curr="";
				}
				else
					resa+=curr+",";
				curr="";
			}
			else{
				resb+=curr+",";
				curr="";
			}
			check=false;
			check2 = false;
			check3 = false;
		}
		else{
			if(i>='0' && i<='9'){
				if(i=='0' && !check3)
					check2 = true;
				if(i!='0' && check2)
					check = true;
				if(i!='0')
					check3 = true;
			}
			else
				check=true;
			curr+=i;
		}
	}
	if(!check && curr!=""){
		if(check2 && curr.size()>1){
			resb+=curr+",";
			curr="";
		}
		else
			resa+=curr+",";
		curr="";
	}
	else{
		resb+=curr+",";
		curr="";
	}
	check=false;
	check2 = false;
	resa.pop_back();
	resb.pop_back();
	resa+="\"";
	resb+="\"";
	cout<<(resa.size()>1 ? resa : "-")<<'\n'<<(resb.size()>1 ? resb : "-")<<'\n'; 


	return 0;
}