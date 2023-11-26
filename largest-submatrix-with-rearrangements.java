import java.util.*;

class Solution {
    public int largestSubmatrix(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[][] heights = new int[m][n];
        for(int j = 0; j < n; j++) {
            int height = 0;
            for(int i = 0; i < m; i++) {
                if(matrix[i][j] == 0) {
                    height = 0;
                } else {
                    height++;
                }
                heights[i][j] = height;
            }
        }
        int max = 0;
        for(int i = 0; i < m; i++) {
            Arrays.sort(heights[i]);
            for(int j = n - 1; j >= 0; j--) {
                max = Math.max(max, heights[i][j] * (n - j));
            }
        }
        return max;
    }
}