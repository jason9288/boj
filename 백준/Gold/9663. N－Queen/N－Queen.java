import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    static int[] col;
    static int N;
    static int cnt = 0;
    static StringBuilder sb;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        col = new int[N+1];
        n_queens(0);
        System.out.println(cnt);
    }

    static void n_queens(int i) {
        int end = col.length - 1;
        if (promising(i)) {
            if (i == end) {
                cnt++;
            } else {
                for (int j = 1; j <= end; j++) {
                    col[i + 1] = j;
                    n_queens(i + 1);
                }
            }
        }
    }

    static boolean promising(int i) {
        int k = 1;
        boolean flag = true;
        while (k < i && flag) {
            if (col[i] == col[k] || Math.abs(col[i] - col[k]) == (i - k)) {
                flag = false;
            }
            k++;
        }
        return flag;
    }
}