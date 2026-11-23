/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if (n == 0)
            return;

        for (int i = 0; i < m; i++) {
            if (nums1[i] > nums2[0]) {
                swap(nums1[i], nums2[0]);
                arrange(nums2, n);
            }
        }

        for (int i = m; i < m + n; i++)
            nums1[i] = nums2[i - m];
    }

    void swap(int& num1, int& num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    void arrange(vector<int>& nums, int n) {
        int i = 1;

        while (i < n && nums[i] < nums[i - 1]) {
            if (nums[i] < nums[i - 1])
                swap(nums[i], nums[i - 1]);
            i++;
        }
    }
};
// @lc code=end
