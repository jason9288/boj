import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {
    static class Pair {
        int x, y;
        Pair(int y, int x) {
            this.x = x;
            this.y = y;
        }
    }
    static Queue<Pair> q = new LinkedList<>();
    static int[] dy = {0, 0, -1, 1};
    static int[] dx = {-1, 1, 0, 0};
    static int[][] map;
    static int[][] dist;
    static boolean[][] visit;
    static int n, m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new int[n][m];
        dist = new int[n][m];
        visit = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            String[] row = br.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(row[j]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 2) {
                    q.add(new Pair(i, j));

                }
            }
        }

        bfs();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dist[i][j] == 0 && map[i][j] != 0 && map[i][j] != 2) {
                    dist[i][j] = -1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(dist[i][j] + " ");
            }
            System.out.println();
        }


    }
    public static void bfs() {
        while (!q.isEmpty()) {
            Pair current = q.poll();
            int x = current.x;
            int y = current.y;
            for (int i = 0; i < 4; i++) {
                int nxt_y = y + dy[i];
                int nxt_x = x + dx[i];
                if (nxt_x >= 0 && nxt_y >= 0 && nxt_x < m && nxt_y < n) {
                    if (map[nxt_y][nxt_x] == 1 && !visit[nxt_y][nxt_x]) {
                        visit[nxt_y][nxt_x] = true;
                        q.add(new Pair(nxt_y, nxt_x));
                        dist[nxt_y][nxt_x] = dist[y][x] + 1;
                    }
                }
            }
        }
    }
}