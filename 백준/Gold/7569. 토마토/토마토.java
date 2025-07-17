import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Pos {
    int x, y, z;
    Pos(int y, int x, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
    int first() {
        return y;
    }
    int second() {
        return x;
    }
    int height() {
        return z;
    }
}
public class Main {
    static int MAX = 101;
    static int n, m, h;
    static int[] dx = {-1, 0, 0, 1, 0, 0};
    static int[] dy = {0, -1, 0, 0, 1, 0};
    static int[] dz = {0, 0, -1, 0, 0, 1};

    static int[][][] tomato = new int[MAX][MAX][MAX];
    static boolean[][][] visited = new boolean[MAX][MAX][MAX];
    static int[][][] dist = new int[MAX][MAX][MAX];
    static Queue<Pos> q = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());

        for (int z = 0; z < h; z++) {
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < m; j++) {
                    tomato[z][i][j] = Integer.parseInt(st.nextToken());
                }
            }
        }


        for (int z = 0; z < h; z++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (tomato[z][i][j] == 1) {
                        q.add(new Pos(i, j, z));
                    }
                }
            }
        }


        bfs();

        for (int z = 0; z < h; z++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (tomato[z][i][j] == 0 && dist[z][i][j] == 0) {
                        System.out.println(-1);
                        return;
                    }
                }
            }
        }


        int day = -1;

        for (int z = 0; z < h; z++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (day < dist[z][i][j]) {
                        day = dist[z][i][j];
                    }
                }
            }
        }

        System.out.println(day);
    }

    static void bfs() {
        while (!q.isEmpty()) {
            int cur_x = q.peek().second();
            int cur_y = q.peek().first();
            int cur_z = q.peek().height();
            q.remove();

            for (int i = 0; i < 6; i++) {
                int new_x = cur_x + dx[i];
                int new_y = cur_y + dy[i];
                int new_z = cur_z + dz[i];

                if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n || new_z < 0 || new_z >= h) { continue; }
                if (tomato[new_z][new_y][new_x] == 0 && !visited[new_z][new_y][new_x]) {
                    visited[new_z][new_y][new_x] = true;
                    q.add(new Pos(new_y, new_x, new_z));
                    dist[new_z][new_y][new_x] = dist[cur_z][cur_y][cur_x] + 1;
                }
            }
        }
    }
}