class Solution {
public:

    // Check if all 4 vertices of the rhombus are inside the grid
    bool check_bounds(vector<vector<int>>& grid, vector<pair<int,int>> v){
        int m = grid.size();
        int n = grid[0].size();

        for(auto &pt : v){
            if(pt.first < 0 || pt.first >= m || pt.second < 0 || pt.second >= n){
                return false;
            }
        }
        return true;
    }

    // Calculate the four vertices of the rhombus for a given center and size (delta)
    bool get_all_v(vector<vector<int>>& grid, vector<pair<int,int>>& v, pair<int,int> c, int delta){

        // Top vertex
        pair<int,int> A(c.first - delta, c.second);

        // Right vertex
        pair<int,int> B(c.first, c.second + delta);

        // Bottom vertex
        pair<int,int> C(c.first + delta, c.second);

        // Left vertex
        pair<int,int> D(c.first, c.second - delta);

        // Store vertices in vector
        v[0] = A;
        v[1] = B;
        v[2] = C;
        v[3] = D;

        // Check if the rhombus is valid (inside grid)
        if(check_bounds(grid, v)) return true;

        return false;
    }

    // Calculate all rhombus sums for a given center cell
    void getAllSum(vector<vector<int>>& grid, int cx, int cy, priority_queue<int>& pq){

        // A single cell is also considered a rhombus (size = 0)
        pq.push(grid[cx][cy]);

        int delta = 1;
        vector<pair<int,int>> v(4);

        // Increase rhombus size until it goes out of grid
        while(get_all_v(grid, v, {cx,cy}, delta)){

            // Get the four vertices
            pair<int,int> A = v[0];
            pair<int,int> B = v[1];
            pair<int,int> C = v[2];
            pair<int,int> D = v[3];

            // Start with the sum of the four vertices
            int c_sum = grid[A.first][A.second] +
                        grid[B.first][B.second] +
                        grid[C.first][C.second] +
                        grid[D.first][D.second];

            // Traverse edge A -> B and add intermediate elements
            for(int i = 1; i < (B.first - A.first); i++){
                c_sum += grid[A.first + i][A.second + i];
            }

            // Traverse edge B -> C
            for(int i = 1; i < (C.first - B.first); i++){
                c_sum += grid[B.first + i][B.second - i];
            }

            // Traverse edge C -> D
            for(int i = 1; i < (C.first - D.first); i++){
                c_sum += grid[C.first - i][C.second - i];
            }

            // Traverse edge D -> A
            for(int i = 1; i < (D.first - A.first); i++){
                c_sum += grid[D.first - i][D.second + i];
            }

            // Push this rhombus sum into the max heap
            pq.push(c_sum);

            // Increase rhombus size
            delta++;
        }
    }

    // Check if the value is already present in the answer vector
    // (because we need distinct values)
    bool can_push(vector<int> ans, int top){
        for(auto val : ans){
            if(val == top) return false;
        }
        return true;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        // This vector will store the final answer
        vector<int> ans;

        int m = grid.size();
        int n = grid[0].size();

        // Max heap to store all rhombus sums
        priority_queue<int> pq;

        // Try every cell as a possible rhombus center
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                getAllSum(grid, i, j, pq);
            }
        }

        // Extract the top 3 distinct maximum sums
        while(!pq.empty() && ans.size() < 3){

            int top = pq.top();
            pq.pop();

            // Only add if it is not already in the answer
            if(can_push(ans, top)){
                ans.push_back(top);
            }
        }

        return ans;
    }
};