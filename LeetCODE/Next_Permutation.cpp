class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int i = a.size()-2;
        while(i>=0 && a[i]>=a[i+1])
            i--;
        if(i>=0){
            int j = a.size()-1;
            while(j>=0 && a[j]<=a[i])
                j--;
            swap(a[i], a[j]);
        }
        reverse(a.begin()+i+1, a.end());
    }
};