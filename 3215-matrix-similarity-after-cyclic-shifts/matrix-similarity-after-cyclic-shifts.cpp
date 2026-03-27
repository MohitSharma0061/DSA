class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        k %= m;

        vector<vector<int>> temp(n, vector<int>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i % 2 == 0) // left shift
                    temp[i][(j + m - k) % m] = mat[i][j];
                else // right shift
                    temp[i][(j + k) % m] = mat[i][j];
            }
        }

        return temp == mat;
    }
};