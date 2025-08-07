// Last updated: 07/08/2025, 12:51:21
class Solution {
public:
    vector<int> spiralOrder(const vector<vector<int>>& matrix) {
        int remaining_count = matrix.size()*matrix[0].size();
        vector<int> answer = {};
        answer.reserve(remaining_count);

        int top_bound = 0;
        int bottom_bound = matrix.size();
        int left_bound = -1;
        int right_bound = matrix[0].size();
        int i = 0, j = 0;
        int mode = 0;
        while (true) {
            std::cout << matrix[i][j] << ' ';
            switch (mode) {
            case 0:
                while (j < right_bound) {
                    answer.push_back(matrix[i][j++]);
                    remaining_count--;
                }
                j--;
                right_bound--;
                if (remaining_count<=0) goto outside;
                mode = 1; i++;
            case 1:
                while (i < bottom_bound) {
                    answer.push_back(matrix[i++][j]);
                    remaining_count--;
                }
                i--;
                bottom_bound--;
                if (remaining_count<=0) goto outside;
                mode = 2; j--;
            case 2:
                while (j > left_bound) {
                    answer.push_back(matrix[i][j--]);
                    remaining_count--;
                }
                j++;
                left_bound++;
                if (remaining_count<=0) goto outside;
                mode = 3; i--;
            case 3:
                while (i > top_bound) {
                    answer.push_back(matrix[i--][j]);
                    remaining_count --;
                }
                i++;
                top_bound++;
                if (remaining_count<=0) goto outside;
                mode = 0; j++;
            }
            if (remaining_count<=0) goto outside;
        }
        outside:
        return answer;
    }
};