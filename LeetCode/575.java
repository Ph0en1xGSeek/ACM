class Solution {
    public int distributeCandies(int[] candies) {
        Set<Integer> st = new HashSet();
        for(int item: candies) {
            st.add(item);
        }
        return Math.min(candies.length / 2, st.size());
    }
}