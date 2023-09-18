class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int[] res = new int[k];
        int[] count = new int[mat.length];
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[0].length; j++) {
                if (mat[i][j] == 1) {
                    count[i]++;
                }
            }
        }
        for (int i = 0; i < k; i++) {
            int min = Integer.MAX_VALUE;
            int index = -1;
            for (int j = 0; j < count.length; j++) {
              
                if (count[j] < min) {
                    min = count[j];
                    index = j;
                }
            }
            res[i] = index;
            count[index] = Integer.MAX_VALUE;
        }
        return res;
    }
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] mat = {{1,1,0,0,0},
                       {1,1,1,1,0},
                       {1,0,0,0,0},
                       {1,1,0,0,0},
                       {1,1,1,1,1}};
        int k = 3;
        int[] result = sol.kWeakestRows(mat, k);
        System.out.println(Arrays.toString(result));
    }
}