// Last updated: 07/08/2025, 12:51:13
class Solution {
private:
    bool searchRow(const vector<int>& row, const int& target) {
        int col_l = 0;
        int col_r = row.size()-1;
        while (col_l <= col_r) {
            int col_m = col_l + (col_r-col_l)/2;
            if (target > row[col_m]) col_l=col_m+1;
            else if (target < row[col_m]) col_r=col_m-1;
            else return true;
        }
        return false;
    }
public:
    bool searchMatrix(const vector<vector<int>>& matrix, const int& target) {
        int row_l = 0;
        int row_r = matrix.size()-1;
        if (row_r == 0) return searchRow(matrix[0], target);

        while (row_l <= row_r) {
            int row_m = row_l + (row_r-row_l)/2;
            if (target > matrix[row_m][0]) row_l=row_m+1;
            else row_r = row_m-1;
        }

        if (row_l == matrix.size())
            return searchRow(matrix[row_l-1], target);
        if (matrix[row_l][0] == target) return true;
        if (row_l-1 < 0) return false;
        return searchRow(matrix[row_l-1], target);
    }
};