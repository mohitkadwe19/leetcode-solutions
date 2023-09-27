class Solution {
    public String decodeAtIndex(String s, int k) {

     long length = 0;
        int i = 0;

        while (length < k) {
            if (Character.isDigit(s.charAt(i))) {
                length *= s.charAt(i) - '0';
            } else {
                length++;
            }
            i++;
        }

        for (int j = i - 1; j >= 0; j--) {
            if (Character.isDigit(s.charAt(j))) {
                length /= s.charAt(j) - '0';
                k %= length;
            } else {
                if (k == 0 || k == length) {
                    return Character.toString(s.charAt(j));
                }
                length--;
            }
        }

        return "";   

    }
    public static void main(String[] args) {
        Solution sol = new Solution();
        String s = "leet2code3";
        int k = 10;
        System.out.println(sol.decodeAtIndex(s, k));
    
    }
}