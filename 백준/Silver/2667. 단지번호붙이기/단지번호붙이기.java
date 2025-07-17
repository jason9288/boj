import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int K;
    static int[][] map;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static boolean[][] visited;
    static int cnt;
    static int house_cnt;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        house_cnt = 0;
        ArrayList<Integer> num_h = new ArrayList<>();
        cnt = 0;

        N = Integer.parseInt(br.readLine());
        map = new int[N][N];
        visited = new boolean[N][N];

        for (int j = 0; j < N; j++) {
            String row = br.readLine();
            for (int k = 0; k < N; k++) {
                map[j][k] = Character.getNumericValue(row.charAt(k));
            }
        }

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (map[j][k] == 1 && !visited[j][k]) {
                    house_cnt = 1;
                    dfs(j, k);
                    num_h.add(house_cnt);
                    cnt++;
                }
            }
        }
        Collections.sort(num_h);
        System.out.println(cnt);
        for (int i : num_h) {
            System.out.println(i);
        }
    }

    public static void dfs(int x, int y) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < N) {
                if (map[next_x][next_y] == 1 && !visited[next_x][next_y]) {
                    dfs(next_x, next_y);
                    house_cnt++;
                }
            }
        }
    }
}