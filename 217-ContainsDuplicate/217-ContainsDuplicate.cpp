// Last updated: 07/08/2025, 12:50:51
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return !(nums.size()==set(nums.begin(),nums.end()).size());
    }
};