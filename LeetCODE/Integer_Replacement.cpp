class Solution {
public:
    int integerReplacement(int n) {
        long long x = n,res = 0;
        while(x>1){
            if(x%2){
                if(x>4 && x%4==3)
                    x++;
                else 
                    x--;
                res++;
            }
            else{
                x/=2;
                res++;
            }
        }
        return res;
    }
};