import java.util.*;

class Solution {
    public int minOperations(List<Integer> nums, int k) {
     
     int len = nums.size();
     
     HashSet<Integer> st = new HashSet<>();
     
     for (int i = 1; i <= k; i++) {
         st.add(i);
     }

     int count = 0;
     
     for (int i=len-1;i>=0; i--) {
      int val = nums.get(i);
      if(st.contains(val)) {
          st.remove(val);
      }
          count++;
      if(st.size() == 0) {
          break;
      }
     }
     return count;
    }
    public static void main(String[] args) {
        Solution sol = new Solution();
        List<Integer> nums = new ArrayList<>();
        nums.add(1);
        nums.add(2);
        nums.add(3);

        System.out.println(sol.minOperations(nums, 5));
    }
}