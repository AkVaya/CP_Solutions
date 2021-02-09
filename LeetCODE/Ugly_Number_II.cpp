class Solution {
public:
    int nthUglyNumber(int n) {
        long long nxt = 1,two = 2, three = 3, five = 5;
        vector<long long>dp(n+1);
        dp[0] = 1; 
        int ind = 0,i2 = 0,i3 = 0,i5 = 0;
        for(int i = 1; i < n; ++i){
            nxt = min(two,min(three,five));
            ++ind;
            dp[ind] = nxt;
            if(nxt==two)
                two = 2*dp[++i2];
            if(nxt==three)
                three = 3*dp[++i3];
            if(nxt==five)
                five = 5*dp[++i5]; 
        }
        return nxt;
        
    }
};