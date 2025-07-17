import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[][] dp;
    static int[][] stickers;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int tc = 0; tc < T; tc++) {
            int n = Integer.parseInt(br.readLine());
            dp = new int[2][n];
            stickers = new int[2][n];

            for (int i = 0; i < 2; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    stickers[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            if (n == 1) {
                System.out.println(Math.max(stickers[1][0], stickers[0][0]));
                continue;
            }

            dp[0][0] = stickers[0][0];
            dp[1][0] = stickers[1][0];
            dp[0][1] = dp[1][0] + stickers[0][1];
            dp[1][1] = dp[0][0] + stickers[1][1];

            for (int i = 2; i < n; i++) {
                dp[0][i] = Math.max(dp[1][i-2], dp[1][i-1]) + stickers[0][i];
                dp[1][i] = Math.max(dp[0][i-2], dp[0][i-1]) + stickers[1][i];
            }

            System.out.println(Math.max(dp[0][n-1], dp[1][n-1]));
        }
    }
}