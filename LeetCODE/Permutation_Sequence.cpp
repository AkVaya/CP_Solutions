class Solution {
public:
    string getPermutation(int n, int k) {
        int left = n-1;
        string curr="";
        int fact[n+1];
        fact[0] = 1;
        for(int i = 1; i <= n; ++i)
            fact[i] = i*fact[i-1];
        vector<bool>check(n+1,false);
        while(left>0){
            for(int i = 1; i <= n; ++i){
                if(!check[i] && k>fact[left]){
                    k-=fact[left];
                }
                else if(!check[i]){
                    --left;
                    check[i] = true;
                    curr+=char(i+'0');
                    break;
                }
            }
        }
        for(int i = 1; i <= n; ++i){
            if(!check[i])
                return curr + char(i+'0');
        }
        return curr;
    }
};