import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void dpf(int n, int[] dp) {
        for (int i = 1; i*i <= n; i++) {
            if (dp[n] == 0) {
                dp[n] = dp[i*i] + dp[n - i*i];
            } else {
                dp[n] = Math.min(dp[n], dp[i*i] + dp[n - i*i]);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bf.readLine());

        int[] dp = new int[50001];
        for (int i = 1; i*i <= n; i++) {
            dp[i*i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (dp[n] != 0) {
                continue;
            }
            dpf(i, dp);
        }

        System.out.print(dp[n]);
    }
}