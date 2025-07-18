import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] board = new int[n][3];
        int[][] mindp = new int[n][3];
        int[][] maxdp = new int[n][3];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 3; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 0; i < 3; i++) {
            mindp[n-1][i] = board[n-1][i];
            maxdp[n-1][i] = board[n-1][i];
        }

        for (int i = n-2; i >= 0; i--) {
            mindp[i][0] = Math.min(mindp[i+1][0], mindp[i+1][1]) + board[i][0];
            maxdp[i][0] = Math.max(maxdp[i+1][0], maxdp[i+1][1]) + board[i][0];

            mindp[i][1] = Math.min(mindp[i+1][0], Math.min(mindp[i+1][1], mindp[i+1][2])) + board[i][1];
            maxdp[i][1] = Math.max(maxdp[i+1][0], Math.max(maxdp[i+1][1], maxdp[i+1][2])) + board[i][1];

            mindp[i][2] = Math.min(mindp[i+1][1], mindp[i+1][2]) + board[i][2];
            maxdp[i][2] = Math.max(maxdp[i+1][1], maxdp[i+1][2]) + board[i][2];
        }

        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < 3; i++) {
            if (maxdp[0][i] > max) {
                max = maxdp[0][i];
            }
            if (mindp[0][i] < min) {
                min = mindp[0][i];
            }
        }

        System.out.println(max + " " + min);
    }
}