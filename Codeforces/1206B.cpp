    #include<bits/stdc++.h>
    using namespace std ;
    int main()
    {
        long long int n, m,sum=0,flag=0 , h=0,x=0;
        cin>>n;
        long long int a[n];
        for(long long int i=0;i<n;i++){
        	cin>>a[i];
        	if(a[i]==0 && x==0){
        		x=1;
        		flag++;		
        	}
        	else if(a[i]<0){
        		h++;
        	}
        	else if(a[i]==0){
        		flag++;
        	}
        	else{
        		continue;
        	}
        
        }
        if((h%2)!=0 && x==0){
        	sum+=2;
        }
        else if(x==1 && h%2!=0){
        	sum++;
        	flag-- ;
        }
     
        for(long long int i=0;i<n;i++){
        	if(a[i]<0 ){
        		sum+=abs(-1-a[i]);
        	}
        	else if(a[i]>0){
     
        		sum+=abs(a[i]-1);
        	}
        	else if(flag>0 ){
    			flag--;
        		sum+=1;
        	}
        }
        
        cout<<sum;
        
        return 0;
    }