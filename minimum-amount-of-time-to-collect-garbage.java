
class Solution {
    public int garbageCollection(String[] garbage, int[] travel) {
        int res = 0;

        for (String g : garbage) {
            res += g.length();
        }

        boolean m = false, p = false, g = false;

        for (int i = travel.length; i > 0; i--) {
            m = m || garbage[i].contains("M");
            p = p || garbage[i].contains("P");
            g = g || garbage[i].contains("G");

            res += travel[i-1] * ((m ? 1 : 0) + (p ? 1 : 0) + (g ? 1 : 0));
        }

        return res;
    }
}