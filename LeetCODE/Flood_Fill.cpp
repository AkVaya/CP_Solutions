class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    bool valid(int i, int j, int n, int m){
        return(i>=0 && i<n && j>=0 && j<m);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int,int> >q;
        q.push({sr, sc});
        vector<vector<bool> >vis(image.size(), vector<bool>(image[0].size(), false));
        int x = image[sr][sc];
        vis[sr][sc] = true;
        while(q.size()){
            int i = q.front().first, j = q.front().second;
            image[i][j] = newColor;
            q.pop();
            for(int a = 0; a < 4; ++a){
                if(valid(i+dx[a], j + dy[a],image.size(), image[0].size()) && !vis[i + dx[a]][j + dy[a]] && image[i + dx[a]][j + dy[a]]==x){
                    vis[i + dx[a]][j + dy[a]] = true;
                    q.push({i + dx[a], j + dy[a]});
                }
            }
        }
        return image;
    }
};