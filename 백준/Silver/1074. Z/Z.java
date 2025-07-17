import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int cnt = 0;
    static void visit(int size, int r, int c) {
        if (size == 1) {
            return;
        }
        if (r < size/2 && c < size/2) {
            visit(size/2, r, c);
        } else if (r < size/2 && c >= size/2) {
            cnt += size*size/4;
            visit(size/2, r, c - size/2);
        } else if (r >= size/2 && c < size/2) {
            cnt += (size*size / 4) * 2;
            visit(size/2, r - size/2, c);
        } else {
            cnt += (size*size / 4) * 3;
            visit(size/2, r - size/2, c - size/2);
        }
    }

    public static void main(String[] args) throws IOException {
        long before = System.currentTimeMillis();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        int size = (int) Math.pow(2, N);
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        visit(size, r, c);
        System.out.println(cnt);

        long after = System.currentTimeMillis();
    }
}