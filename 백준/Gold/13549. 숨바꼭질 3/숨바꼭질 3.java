import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int time = 0;
    static int[] dp;
    public static void getMinTime(int pos) {
        if (pos % 2 == 0) {
            int min = Math.min(dp[pos-1], dp[pos+1]);
            if (min < dp[pos/2]) {
                dp[pos] = min+1;
            } else {
                dp[pos] = dp[pos/2];
            }
        } else {
            dp[pos] = Math.min(dp[pos-1], dp[pos+1]) + 1;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        dp = new int[100002];
        for (int i = 0; i < 100002; i++) {
            dp[i] = Integer.MAX_VALUE;
        }

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        for (int i = N; i >= 0; i--) {
            dp[i] = N-i;
        }
        for (int i = N+1; i < 100001; i++) {
            getMinTime(i);
        }
        for (int i = N+1; i < 100001; i++) {
            getMinTime(i);
        }
        for (int i = N+1; i < 100001; i++) {
            getMinTime(i);
        }


        System.out.println(dp[K]);
    }
}