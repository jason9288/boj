import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static class Register {
        int num;
        String com;
        Register(int num, String com) {
            this.num = num;
            this.com = com;
        }
        int D() {
            return (num*2) % 10000;
        }
        int S() {
            return num == 0 ? 9999 : num-1;
        }
        int L() {
            return num%1000 * 10 + num/1000;
        }
        int R() {
            return num%10 * 1000 + num/10;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (int tc = 0; tc < T; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            boolean[] visited = new boolean[10000];
            visited[A] = true;

            Queue<Register> q = new LinkedList<>();
            q.add(new Register(A, ""));

            String ans = "";
            while (!q.isEmpty()) {
                Register now = q.poll();

                if (now.num == B) {
                    System.out.println(now.com);
                    break;
                }
                if (!visited[now.D()]) {
                    q.add(new Register(now.D(), now.com + "D"));
                    visited[now.D()] = true;
                }
                if (!visited[now.S()]) {
                    q.add(new Register(now.S(), now.com + "S"));
                    visited[now.S()] = true;
                }
                if (!visited[now.L()]) {
                    q.add(new Register(now.L(), now.com + "L"));
                    visited[now.L()] = true;
                }
                if (!visited[now.R()]) {
                    q.add(new Register(now.R(), now.com + "R"));
                    visited[now.R()] = true;
                }
            }
        }
    }
}
