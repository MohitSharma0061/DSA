class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int row=matrix.size();
        int col=matrix[0].size();
        int count=0;

        int total=row*col;
        int startingrow=0;
        int startingcol=0;
        int endingrow=row-1;
        int endingcol=col-1;

        while(count<total){
            // starting row print
            for(int index=startingcol; index<=endingcol && count<total; index++){
                ans.push_back(matrix[startingrow][index]);
                count++;

            }
            startingrow++;
            // endingcol printing
            for(int index=startingrow; index<=endingrow && count<total; index++){
                ans.push_back(matrix[index][endingcol]);
                count++;
            }
            endingcol--;
            //ending row printing
            for(int index=endingcol; index>=startingcol && count<total; index--){
                ans.push_back(matrix[endingrow][index]);
                count++;

            }
            endingrow--;
            //startingcol printing
            for(int index=endingrow; index>=startingrow && count<total; index--){
                ans.push_back(matrix[index][startingcol]);
                count++;
            }
            startingcol++;
        }
        return ans;
    }
};