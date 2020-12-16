class Solution {
public:
    bool backtrack(vector<vector<char>>& board,int i,int j){
        if(j==9){
            j = 0;
            i++;
            if(i==9)
                return true;
        }
        if(board[i][j]!='.')
            return backtrack(board,i,j+1);
        for(char a = '1'; a <= '9'; ++a){
            bool check = false;
            for(int x = 0; x < 9; ++x)
                if(board[i][x]==a || board[x][j]==a){
                    check=true;
                    break;
                }
                if(check)
                    continue;
                for(int y = 0; y < 3; ++y){
                    for(int x = 0; x < 3; ++x){
                        if(board[x+(i/3)*3][y+(j/3)*3]==a){
                            check=true;
                            break;
                        }
                    }
                }
                if(!check){
                    board[i][j] = a;
                    if(backtrack(board,i,j))
                        return true;
                    board[i][j] = '.';
                }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board,0,0);
    }
};