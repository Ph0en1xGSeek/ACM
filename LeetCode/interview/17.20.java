class MedianFinder {

    private Queue<Integer> mx = new PriorityQueue<Integer>();
    private Queue<Integer> mi = new PriorityQueue<Integer>(new Comparator<Integer>() {
        @Override
        public int compare(Integer a, Integer b) {
            return b - a;
        }
    });

    /** initialize your data structure here. */
    public MedianFinder() {

    }

    private void balance() {
        int mi_size = mi.size();
        int mx_size = mx.size();
        if(mi_size - mx_size > 1) {
            mx.offer(mi.peek());
            mi.poll();
        }else if(mx_size - mi_size > 1) {
            mi.offer(mx.peek());
            mx.poll();
        }
    }
    
    public void addNum(int num) {
        if(mi.isEmpty() && mx.isEmpty()) {
            mi.offer(num);
        }else if(mi.isEmpty()) {
            if(num > mx.peek()) {
                mx.offer(num);
            }else {
                mi.offer(num);
            }
        }else {
            if(num < mi.peek()) {
                mi.offer(num);
            }else {
                mx.offer(num);
            }
        }
        balance();
    }
    
    public double findMedian() {
        int mi_size = mi.size();
        int mx_size = mx.size();
        if(mi_size == mx_size) {
            return (mx.peek() + mi.peek()) / 2.0;
        }else if(mi_size > mx_size) {
            return mi.peek();
        }else {
            return mx.peek();
        }
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */