class Solution {
    public int translateNum(int num) {
        if(num == 0) {
            return 1;
        }
        List<Integer> list = new ArrayList<>();
        while(num > 0) {
            list.add(num % 10);
            num /= 10;
        }
        Collections.reverse(list);
        int pre_pre = 0, pre = 1, cur = 1;
        int size = list.size();
        for(int i = 1; i < size; ++i) {
            pre_pre = pre;
            pre = cur;
            if(list.get(i-1) == 1) {
                cur += pre_pre;
            }else if(list.get(i-1) == 2 && list.get(i) < 6) {
                cur += pre_pre;
            }
        }
        return cur;
    }
}