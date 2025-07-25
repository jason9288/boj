import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[] R;
    static int[] G;
    static int[] B;
    static int sum = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        R = new int[N];
        G = new int[N];
        B = new int[N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            R[i] = Integer.parseInt(st.nextToken());
            G[i] = Integer.parseInt(st.nextToken());
            B[i] = Integer.parseInt(st.nextToken());
        }

        int[][] ans = new int[N+1][4];

        for (int i = 1; i < N+1; i++) {
            ans[i][0] = Math.min(ans[i-1][1], ans[i-1][2]) + R[i-1];
            ans[i][1] = Math.min(ans[i-1][0], ans[i-1][2]) + G[i-1];
            ans[i][2] = Math.min(ans[i-1][0], ans[i-1][1]) + B[i-1];
        }
        System.out.println(Math.min(Math.min(ans[N][0], ans[N][1]), ans[N][2]));
    }


}