import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Pair {
    int x, y;
    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
    int first() {
        return x;
    }
    int second() {
        return y;
    }
}
public class Main {
    static int MAX = 1001;
    static int n, m;
    static int[] dx = {-1, 1, 0, 0}; //0, 0};
    static int[] dy = {0, 0, -1, 1}; // 0, 0};
//    static int[] dz = {0, 0, 0, 0, -1, 1};

    static int[][] tomato = new int[MAX][MAX];
    static boolean[][] visited = new boolean[MAX][MAX];
    static int[][] dist = new int[MAX][MAX];
    static Queue<Pair> q = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                tomato[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (tomato[i][j] == 1) {
                    q.add(new Pair(i, j));
                }
            }
        }

        bfs();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (tomato[i][j] == 0 && dist[i][j] == 0) {
                    System.out.println(-1);
                    return;
                }
            }
        }

        int day = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (day < dist[i][j]) {
                    day = dist[i][j];
                }
            }
        }
        System.out.println(day);
    }

    static void bfs() {
        while (!q.isEmpty()) {
            int cur_x = q.peek().second();
            int cur_y = q.peek().first();
            q.remove();

            for (int i = 0; i < 4; i++) {
                int new_x = cur_x + dx[i];
                int new_y = cur_y + dy[i];

                if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n) { continue; }
                if (tomato[new_y][new_x] == 0 && !visited[new_y][new_x]) {
                    visited[new_y][new_x] = true;
                    q.add(new Pair(new_y, new_x));
                    dist[new_y][new_x] = dist[cur_y][cur_x] + 1;
                }
            }
        }
    }
}