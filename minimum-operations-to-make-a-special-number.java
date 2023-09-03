import java.util.*;
import java.io.*;

class Solution {
   
    public int minimumOperations(String num) {
   
        int ans= num.length() ,  n = num.length();
     
        if(num.length()==1) {
        if(num.equals("0")) return 0;
            return 1;
        }
        
        for(int i=n-1;i>0;i--) {
            
            if(num.charAt(i)=='0') ans = Math.min(ans,num.length()-1);
            
            for(int j=i-1;j>=0;j--) {
                
                String check = Character.toString(num.charAt(j)) + Character.toString(num.charAt(i));
             
                if(Integer.parseInt(check)%25==0) {
                    ans = Math.min(ans,n-i-1 + (i-j-1));
                }
                
            }
        }

   return ans;
  }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String num = br.readLine();
        int ans = new Solution().minimumOperations(num);
        System.out.println(ans);
    }
}