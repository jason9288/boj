import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {

    static int MAX = 101;
    static int n;
    static int R = 0;
    static int G = 0;
    static int B = 0;
    static int RG = 0;
    static char[][] img = new char[MAX][MAX];
    static boolean[][] visited = new boolean[MAX][MAX];
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            for (int j = 0; j < n; j++) {
                img[i][j] = line.charAt(j);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (img[i][j] == 'R') {
                        dfsR(i, j);
                        R++;
                    }
                    if (img[i][j] == 'G') {
                        dfsG(i, j);
                        G++;
                    }
                    if (img[i][j] == 'B') {
                        dfsB(i, j);
                        B++;
                    }
                }
            }
        }

        visited = new boolean[MAX][MAX];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (img[i][j] == 'R' || img[i][j] == 'G') {
                        dfsRG(i, j);
                        RG++;
                    }
                }
            }
        }

        System.out.println((R+G+B) + " " + (RG+B));

    }
    public static void dfsRG(int x, int y) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nxt_x = x + dx[i];
            int nxt_y = y + dy[i];
            if (nxt_x >= 0 && nxt_y >= 0 && nxt_x < n && nxt_y < n) {
                if ((img[nxt_x][nxt_y] == 'G' || img[nxt_x][nxt_y] == 'R') && (!visited[nxt_x][nxt_y])) {
                    dfsRG(nxt_x, nxt_y);
                }
            }
        }
    }

    public static void dfsR(int x, int y) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nxt_x = x + dx[i];
            int nxt_y = y + dy[i];
            if (nxt_x >= 0 && nxt_y >= 0 && nxt_x < n && nxt_y < n) {
                if (img[nxt_x][nxt_y] == 'R' && (!visited[nxt_x][nxt_y])) {
                    dfsR(nxt_x, nxt_y);
                }
            }
        }
    }
    public static void dfsG(int x, int y) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nxt_x = x + dx[i];
            int nxt_y = y + dy[i];
            if (nxt_x >= 0 && nxt_y >= 0 && nxt_x < n && nxt_y < n) {
                if (img[nxt_x][nxt_y] == 'G' && (!visited[nxt_x][nxt_y])) {
                    dfsG(nxt_x, nxt_y);
                }
            }
        }
    }
    public static void dfsB(int x, int y) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nxt_x = x + dx[i];
            int nxt_y = y + dy[i];
            if (nxt_x >= 0 && nxt_y >= 0 && nxt_x < n && nxt_y < n) {
                if (img[nxt_x][nxt_y] == 'B' && (!visited[nxt_x][nxt_y])) {
                    dfsB(nxt_x, nxt_y);
                }
            }
        }
    }
}