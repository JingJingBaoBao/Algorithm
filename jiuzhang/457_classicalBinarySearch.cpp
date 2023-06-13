class Solution {
public:
    /**
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int findPosition(vector<int> &nums, int target) {
        // write your code here
        return binarySearch(0, nums.size() - 1, nums, target);
    }
    int binarySearch(int start, int end, vector<int> &nums, int target)
    {
        if (start > end) {
            return -1;
        }
        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            return binarySearch(mid + 1, end, nums, target);
        }
        return binarySearch(0, mid - 1, nums, target);
    }
};