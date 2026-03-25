
#define ll long long

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<ll>> sumGrid(m, vector<ll>(n) );

        // i=0 base case
        ll prefSum = 0;
        for ( int j=0; j<n; j++ ) {
            prefSum += 1LL*grid[0][j];
            sumGrid[0][j] = prefSum;
        }

        for ( int i=1; i<m; i++ ) {
            ll prefSum = 0;
            for ( int j=0; j<n; j++ ) {
                prefSum += 1LL*grid[i][j];
                sumGrid[i][j] = prefSum + sumGrid[i-1][j];
            }
        }

        ll totalSum = sumGrid[m-1][n-1];

        // columns partition
        for ( int j=0; j<n-1; j++ ) {
            if ( sumGrid[m-1][j] == totalSum - sumGrid[m-1][j] ) return true;
        }

        // rows partition
        for ( int i=0; i<m-1; i++ ) {
            if ( sumGrid[i][n-1] == totalSum - sumGrid[i][n-1] ) return true;
        }

        return false; // not found

    }
};