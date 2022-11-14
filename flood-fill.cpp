// https://leetcode.com/problems/flood-fill/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        int temp = image[sr][sc];
        int row = image.size();
        int col = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        int a[] = {-1, 1, 0, 0};
        int b[] = {0, 0, -1, 1};
        while(!q.empty()){
            int n = q.size();
            while(n--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k = 0; k<4; k++){
                    int inew = i + a[k];
                    int jnew = j + b[k];
                    if(inew >= 0 && inew < row && jnew >= 0 && jnew < col && image[inew][jnew] == temp){
                        q.push({inew, jnew});
                        image[inew][jnew] = color;
                    }

                }
            }
        }
        return image;
    }
};
