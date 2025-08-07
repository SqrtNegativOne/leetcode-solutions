// Last updated: 07/08/2025, 12:51:31
class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int n = nums.size();
        int l = 0; int r = n-1;
        if (nums[l] <= nums[r]) { // Array was never rotated
            int answer = std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            if (answer == n or nums[answer] != target) return -1;
            return answer;                   
        }

        int pivot = -1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (m!=0 and nums[m] < nums[m-1]) {
                pivot = m;
                break;
            }
            
            if (nums[m] < nums[n-1]) { // m is at right line
                r = m-1;
            } else { // m at left line
                l = m+1;
            }
        }
        std::cout << pivot << '\n';

        if (target < nums[0]) { // target in right line
            int answer = std::lower_bound(nums.begin() + pivot, nums.end(), target) - nums.begin();
            if (answer == n or nums[answer] != target) return -1;
            return answer;
        } else {                // target in left line
            int answer = std::lower_bound(nums.begin(), nums.begin() + pivot, target) - nums.begin();
            if (answer == n or nums[answer] != target) return -1;
            return answer;
        }
    }
};