// Last updated: 07/08/2025, 12:50:26
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        return middleSearch(arr, 0, arr.size());
    }
private:
    int middleSearch(vector<int>& arr, int start, int end) {
        if (end - start == 1) return start;
        int mid = start + (end - start) / 2;
        int left_mid = start + (mid - start) / 2;
        int right_mid = mid + (end - mid) / 2;
        if (right_mid == mid) right_mid++;

        cout << left_mid << ' ' << mid << ' ' << right_mid << '\n';

        int left_value = arr[left_mid];
        int right_value = arr[right_mid];
        int mid_value = arr[mid];
        if (left_value > mid_value && mid_value > right_value) return middleSearch(arr, start, mid);
        else if (left_value < mid_value && mid_value < right_value) return middleSearch(arr, mid+1, end);
        else return middleSearch(arr, left_mid+1, right_mid);
    }
};