class Solution {
     public int poorPigs(int buckets, int tdie, int ttest) {
        int test_val = ttest/tdie;
        int count=0;
        
        while( Math.pow(test_val+1,count) < buckets ){
            count++;
        }
        
        return count;
    }
}