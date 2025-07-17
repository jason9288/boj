import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        Queue<Integer> q = new LinkedList<>();
        int last = 100;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            String command = st.nextToken();

            if (command.equals("push")) {
                int x = Integer.parseInt(st.nextToken());
                last = x;
                q.add(x);
            } else if (command.equals("pop")) {
                if (q.isEmpty()) {
                    bw.write(-1 + "\n");
                } else {
                    bw.write(q.poll() + "\n");
                }
            } else if (command.equals("size")) {
                bw.write((q.size() + "\n"));
            } else if (command.equals("empty")) {
                if (q.isEmpty()) {
                    bw.write(1 + "\n");
                } else {
                    bw.write(0 + "\n");
                }
            } else if (command.equals("front")) {
                if (q.isEmpty()) {
                    bw.write(-1 + "\n");
                } else {
                    bw.write(q.peek() + "\n");
                }
            } else if (command.equals("back")) {
                if (q.isEmpty()) {
                    bw.write(-1 + "\n");
                } else {
                    bw.write(last + "\n");
                }
            }
        }
        bw.flush();
    }
}