class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i = 0, n = matrix.size();
        while(i<n){
            int tempi = i,tempj = i;
            while(tempi<n)
                swap(matrix[i][tempj++],matrix[tempi++][i]);
            i++;
        }
        for(int i = 0; i < n; ++i){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};