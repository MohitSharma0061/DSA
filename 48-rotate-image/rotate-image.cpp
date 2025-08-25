class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = n - 1;
        int endingCol = n - 1;

        // Process layers
        while (startingRow < endingRow && startingCol < endingCol) {
            for (int i = 0; i < endingCol - startingCol; i++) {
                int temp = matrix[startingRow][startingCol + i];

                // left -> top
                matrix[startingRow][startingCol + i] = matrix[endingRow - i][startingCol];

                // bottom -> left
                matrix[endingRow - i][startingCol] = matrix[endingRow][endingCol - i];

                // right -> bottom
                matrix[endingRow][endingCol - i] = matrix[startingRow + i][endingCol];

                // top (temp) -> right
                matrix[startingRow + i][endingCol] = temp;
            }
            startingRow++;
            startingCol++;
            endingRow--;
            endingCol--;
        }
    }
};
