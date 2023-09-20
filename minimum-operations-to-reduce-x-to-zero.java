class Solution {
    public int minOperations(int[] nums, int x) {
       int totalSum = Arrays.stream(nums).sum();
        int target = totalSum - x; 

        if (target < 0)
            return -1; 

        if (target == 0)
            return nums.length; 

        int n = nums.length; 
        int minOperations = Integer.MAX_VALUE; 
        int currentSum = 0; 
        int leftIndex = 0, rightIndex = 0;

        while (rightIndex < n) {
            currentSum += nums[rightIndex];
            rightIndex++;

            while (currentSum > target && leftIndex < n) {
                currentSum -= nums[leftIndex];
                leftIndex++;
            }

            if (currentSum == target)
                minOperations = Math.min(minOperations, n - (rightIndex - leftIndex));
        }

        return (minOperations == Integer.MAX_VALUE) ? -1 : minOperations;
    }
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {1,1,4,2,3};
        int x = 5;
        System.out.println(sol.minOperations(nums, x));

    }
}