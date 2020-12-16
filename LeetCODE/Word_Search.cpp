class Solution {
public:
    bool backtrack(vector<vector<char>>& board,string &word,int ind,int i,int j){
        if(i==-1 || j==-1 ||i == board.size() || j==board[0].size() || ind==word.length() || word[ind]!=board[i][j])
            return false;
        if(ind==word.length()-1)
            return true;
        char temp = board[i][j];
        board[i][j]=' ';
        bool res = (backtrack(board,word,ind+1,i+1,j) || 
                    backtrack(board,word,ind+1,i,j-1) || 
                    backtrack(board,word,ind+1,i,j+1) || 
                    backtrack(board,word,ind+1,i-1,j));
        board[i][j] = temp;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(!board.size())
            return word=="";
        for(int i = 0; i < board.size(); ++i)
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == word[0] && backtrack(board,word,0,i,j))
                    return true;
            }
        return false;
        
    }
};