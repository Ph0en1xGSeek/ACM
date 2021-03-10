import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Integer num = Integer.valueOf(sc.nextLine());
        Stack<Integer> st1 = new Stack();
        Stack<Integer> st2 = new Stack();
        for(int i = 0; i < num; ++i) {
            String[] line = sc.nextLine().split(" ");
            String op = line[0];
            if(op.equals("add")) {
                Integer item = Integer.valueOf(line[1]);
                st1.push(item);
            }else if(op.equals("poll")) {
                if(st2.empty()) {
                    while(!st1.empty()) {
                        Integer temp = st1.peek();
                        st1.pop();
                        st2.push(temp);
                    }
                }
                st2.pop();
            }else {
                if(st2.empty()) {
                    while(!st1.empty()) {
                        Integer temp = st1.peek();
                        st1.pop();
                        st2.push(temp);
                    }
                }
                if(!st2.empty())
                    System.out.println(st2.peek());
            }
        }
    }
}