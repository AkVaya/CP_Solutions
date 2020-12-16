class Solution {
public:
    bool is_attacked(vector<string>&curr,int i,int j,int n){
        for(int x = 0; x < n; ++x)
            if(x!=i && curr[x][j]=='Q' || curr[i][x]=='Q')
                return true;
        int x = i+1, y = j+1;
        while(x<n && y<n)
            if(curr[x++][y++]=='Q')
                return true;
        x = i-1, y = j-1;
        while(x>=0 && y>=0)
            if(curr[x--][y--]=='Q')
                return true;
        x = i+1, y = j-1;
        while(x<n && y>=0)
            if(curr[x++][y--]=='Q')
                return true;
        x = i-1, y = j+1;
        while(x>=0 && y<n)
            if(curr[x--][y++]=='Q')
                return true;
        return false;
         
    }
    void backtrack(vector<vector<string>>&res,vector<string>&curr,int i,int n,int total){
        if(n==0){
            res.push_back(curr);
            return;
        }
        int j = 0;
        while(j<total){
            if(!is_attacked(curr,i,j,total)){
                curr[i][j] = 'Q';
                backtrack(res,curr,(i+1)%total,n-1,total);
                curr[i][j] = '.';
            }
            j++;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> curr(n);
        string temp = "";
        for(int i = 0; i < n; ++i){
            temp+='.';
        }
        for(int i = 0; i < n; ++i){
            curr[i]=(temp);
        }
        backtrack(res,curr,0,n,n);
        return res;
    }
};