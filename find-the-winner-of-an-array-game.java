class Solution {
    public int getWinner(int[] arr, int k) {
       int currentWinner = arr[0];
       int winner =0;
       for(int i=1;i<arr.length;i++){
           if(arr[i]>currentWinner){
               currentWinner = arr[i];
               winner = 0;
           }
           if(++winner == k){
               break;
           }
           
       }
       return currentWinner;
    }
}