import java.io.*;
import java.util.*;

public class Main {
    static int[][] paper;
    static int n, m;
    static int max = Integer.MIN_VALUE;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static boolean[][] visited;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        paper = new int[n][m];
        visited = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                paper[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = true;
                dfs(i, j, 1, paper[i][j]);
                visited[i][j] = false;
                chkagn(0, 0, i, j, paper[i][j]);
            }
        }
        System.out.println(max);
    }
    static void chkagn(int cnt, int start, int x, int y, int sum) {
        if (cnt == 3) {
            max = Math.max(max, sum);
            return;
        }
        for (int i = start; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                chkagn(cnt+1, i+1, x, y, sum+paper[nx][ny]);
            }
        }
    }


    static void dfs(int x, int y, int cnt, int sum) {
        if (cnt == 4) {
            max = Math.max(max, sum);
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    dfs(nx, ny, cnt+1, sum+paper[nx][ny]);
                    visited[nx][ny] = false;
                }
            }
        }
    }
}