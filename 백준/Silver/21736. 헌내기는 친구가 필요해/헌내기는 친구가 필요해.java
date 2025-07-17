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
    static char[][] map;
    static boolean[][] visit;
    static int n, m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        map = new char[n][m];
        visit = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            String row = br.readLine();
            for (int j = 0; j < m; j++) {
                map[i][j] = row.charAt(j);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 'I') {
                    q.add(new Pair(i, j));
                }
            }
        }

        bfs();

        if (cnt > 0) {
            System.out.println(cnt);
        } else {
            System.out.println("TT");
        }
    }

    static int cnt = 0;
    public static void bfs() {
        while (!q.isEmpty()) {
            Pair current = q.poll();
            int x = current.x;
            int y = current.y;
            for (int i = 0; i < 4; i++) {
                int nxt_y = y + dy[i];
                int nxt_x = x + dx[i];
                if (nxt_x >= 0 && nxt_y >= 0 && nxt_x < m && nxt_y < n) {
                    if (map[nxt_y][nxt_x] == 'O' && !visit[nxt_y][nxt_x]) {
                        visit[nxt_y][nxt_x] = true;
                        q.add(new Pair(nxt_y, nxt_x));
                    }
                    if (map[nxt_y][nxt_x] == 'P' && !visit[nxt_y][nxt_x]) {
                        cnt++;
                        visit[nxt_y][nxt_x] = true;
                        q.add(new Pair(nxt_y, nxt_x));
                    }
                }
            }
        }
    }
}