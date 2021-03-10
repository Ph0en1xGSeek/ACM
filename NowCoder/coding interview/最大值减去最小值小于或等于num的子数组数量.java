import java.util.Scanner;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, num;
        n = sc.nextInt();
        num = sc.nextInt();
        int cur;
        int[] arr = new int[n];
        for(int i = 0; i < n; ++i) {
            arr[i] = sc.nextInt();
        }
        if(num == 0) {
            System.out.println((long)n * (long)(n - 1) / 2);
            return;
        }
        LinkedList<Integer> mi = new LinkedList<>();
        LinkedList<Integer> mx = new LinkedList<>();
        int ans = 0;
        int left = 0;
        for(int i = 0; i < n; ++i) {
            while(mi.size() != 0 && arr[mi.getLast()] > arr[i]) {
                mi.pollLast();
            }
            mi.addLast(i);
            while(mx.size() != 0 && arr[mx.getLast()] < arr[i]) {
                mx.pollLast();
            }
            mx.addLast(i);
            while(left <= i && arr[mx.getFirst()] - arr[mi.getFirst()] > num) {
                ++left;
                if(mi.getFirst() < left) {
                    mi.pollFirst();
                }
                if(mx.getFirst() < left) {
                    mx.pollFirst();
                }
            }
            ans += i - left + 1;
        }
        System.out.println(ans);
    }
};