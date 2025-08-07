// Last updated: 07/08/2025, 12:51:05
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return {{1}};
        if (numRows == 2) return {{1}, {1, 1}};

        std::vector<vector<int>> answer = {{1}, {1, 1}};
        answer.reserve(numRows);

        for (int row = 2; row < numRows; row++) {
            std::vector<int> newRow = {1};
            newRow.reserve(row);

            std::vector<int>& prevRow = answer[row-1];

            for (int cell = 1; cell < row; cell++) {
                newRow.push_back(prevRow[cell-1] + prevRow[cell]);
            }
            newRow.push_back(1);
            answer.push_back(newRow);
        }

        return answer;
    }
};