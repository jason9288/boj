import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.Deque;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        outerloop :
        for (int tc = 0; tc < T; tc++) {
            Deque<Integer> d = new LinkedList<>();
            String p = br.readLine();
            int n = Integer.parseInt(br.readLine());
            String arr = br.readLine();

            if (n == 0) {
                if (p.contains("D")) {
                    System.out.println("error");
                } else {
                    System.out.println("[]");
                }
                continue outerloop;
            }

            int cur = 1;
            for (int i = 0; i < n; i++) {
                String add = "";
                for (int j = 0; j < 3; j++) {
//                    System.out.println("cur : " + cur);
                    if (arr.charAt(cur) == ',' || arr.charAt(cur) == ']') {
                        break;
                    }
                    add += arr.charAt(cur);
                    cur++;
                }
                cur++;
//                System.out.println("add: " + add);
                d.addFirst(Integer.parseInt(add));
            }
//            System.out.println(d);

            boolean reverse = false;

            Integer chk = 1;
            for (int i = 0; i < p.length(); i++) {
                if (p.charAt(i) == 'R') {
                    reverse = !reverse;
                } else {
                    if (reverse) {
                        chk = d.pollFirst();
                    } else {
                        chk = d.pollLast();
                    }
                    n--;
                }
                if (chk == null) {
                    System.out.println("error");
                    continue outerloop;
                }
            }
//            System.out.println(d);


            StringBuilder sb = new StringBuilder();
            sb.append("[");
            if (reverse) {
                for (int i = 0; i < n; i++) {
                    sb.append(d.pollFirst());
                    sb.append(",");
                }
            } else {
                for (int i = 0; i < n; i++) {
                    sb.append(d.pollLast());
                    sb.append(",");
                }
            }
            if (sb.length() == 1) {
                sb.append("]");
            } else {
                sb.deleteCharAt(sb.length() - 1);
                sb.append("]");
            }
            System.out.println(sb.toString());
        }
    }
}