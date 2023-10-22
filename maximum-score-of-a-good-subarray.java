class Solution {
    public int maximumScore(int[] nums, int k) {
      int i = k;
        int j = k;
        int maxi = Integer.MIN_VALUE;
        int n = nums.length;
        int mini = nums[k];
        while (i >= 0 && j < n) {
            maxi = Math.max(maxi, mini * (j - i + 1));
            if (j + 1 < n && i - 1 >= 0) {
                if (nums[j + 1] > nums[i - 1]) {
                    j++;
                    mini = Math.min(mini, nums[j]);
                } else {
                    i--;
                    mini = Math.min(mini, nums[i]);
                }
            } else if (j + 1 >= n) {
                i--;
                if (i >= 0) {
                    mini = Math.min(mini, nums[i]);
                }
            } else if (i - 1 < 0) {
                j++;
                if (j < n) {
                    mini = Math.min(mini, nums[j]);
                }
            }
        }
        return maxi;       
    }
}