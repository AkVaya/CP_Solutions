class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int restore = 1;
        while(m!=n){
            m>>=1;
            n>>=1;
            restore<<=1;
        }
        return n*restore;
        
    }
};