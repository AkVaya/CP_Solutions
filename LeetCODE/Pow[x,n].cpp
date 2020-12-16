class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        bool check = n<0;
        while(n){
            if(n%2)
                res = res*x;
            x = x*x;
            n/=2;
        }
        if(check)
            res = 1.0/res;
        return res;
    }
};