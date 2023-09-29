lass Solution {
    public boolean isMonotonic(int[] nums) {
        boolean increasing = true, decreasing = true;
        for(int i = 0; i < nums.length - 1; i++){
            if(nums[i] > nums[i + 1]){
                increasing = false;
            }
            if(nums[i] < nums[i + 1]){
                decreasing = false;
            }
        }
        return increasing || decreasing;
    }
    public static void main(String[] args){
        Solution sol = new Solution();
        int[] nums = {1,2,2,3};
        System.out.println(sol.isMonotonic(nums));
    }
}