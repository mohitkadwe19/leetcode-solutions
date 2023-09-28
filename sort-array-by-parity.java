class Solution {
    public int[] sortArrayByParity(int[] nums) {
        
        int i=0;
        int j=nums.length-1;
        
        while(i<j){
            if(nums[i]%2!=0 && nums[j]%2==0){
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
            if(nums[i]%2==0){
                i++;
            }
            if(nums[j]%2!=0){
                j--;
            }
        }
        return nums;
    }
    public static void main(String[] args){
        Solution sol = new Solution();
        int[] nums = {3,1,2,4};
        int[] result = sol.sortArrayByParity(nums);
        System.out.println(Arrays.toString(result));
    }
}