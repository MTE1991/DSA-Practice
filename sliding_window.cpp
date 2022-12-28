/*
Given an array of positive integers nums and an integer k,
find the length of the longest subarray whose sum is less than or equal to k.
https://leetcode.com/explore/interview/card/leetcodes-interview-crash-course-data-structures-and-algorithms/703/arraystrings/4502/
*/

int findLength(vector<int>& nums, int k) {
    int left = 0, curr = 0, ans = 0;
    for (int right = 0; right < nums.size(); right++) {
        curr += nums[right];
        while (curr > k) {
            curr -= nums[left];
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
}
