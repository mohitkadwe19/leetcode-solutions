import java.util.*;

class Solution {
    Set<String> st = new HashSet<>();
    String ans = "";

    void dfs(String s, int n) {
        if (s.length() == n) {
            if (!st.contains(s) && ans.equals("")) {
                ans = s;
            }
            return;
        }

        dfs(s + '0', n);
        dfs(s + '1', n);
    }

    public String findDifferentBinaryString(String[] nums) {

        for (String num : nums) {
            st.add(num);
        }

        int n = nums[0].length();

        dfs("", n);

        return ans;
    }

}