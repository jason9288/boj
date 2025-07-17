import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        Deque<Integer> q = new ArrayDeque<>();
        int last = 100;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int command = Integer.parseInt(st.nextToken());

            if (command == 1) {
                int x = Integer.parseInt(st.nextToken());
                q.addFirst(x);
            } else if (command == 2) {
                int x = Integer.parseInt(st.nextToken());
                q.addLast(x);
            } else if (command == 3) {
                if (q.isEmpty()) {
                    bw.write(-1 + "\n");
                } else {
                    bw.write(q.removeFirst() + "\n");
                }
            } else if (command == 4) {
                if (q.isEmpty()) {
                    bw.write(-1 + "\n");
                } else {
                    bw.write(q.removeLast() + "\n");
                }
            } else if (command == 5) {
                bw.write((q.size() + "\n"));
            } else if (command == 6) {
                if (q.isEmpty()) {
                    bw.write(1 + "\n");
                } else {
                    bw.write(0 + "\n");
                }
            } else if (command == 7) {
                if (q.isEmpty()) {
                    bw.write(-1 + "\n");
                } else {
                    bw.write(q.peekFirst() + "\n");
                }
            } else if (command == 8) {
                if (q.isEmpty()) {
                    bw.write(-1 + "\n");
                } else {
                    bw.write(q.peekLast() + "\n");
                }
            }
        }
        bw.flush();
    }
}