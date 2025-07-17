import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int R, C;
    static int[][] board;
    static boolean[] alphaV;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int max = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        board = new int[R][C];
        alphaV = new boolean[26];

        for (int i = 0; i < R; i++) {
            String input = br.readLine();
            for (int j = 0; j < C; j++) {
                board[i][j] = input.charAt(j) - 'A';
            }
        }

        backtrack(0, 0, 1);
        System.out.println(max);

    }
    static void backtrack(int x, int y, int len) {
        alphaV[board[x][y]] = true;
        max = Math.max(max, len);
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny)) {
                if (alphaV[board[nx][ny]]) {
                    continue;
                }
                backtrack(nx, ny, len+1);
                alphaV[board[nx][ny]] = false;
            }
        }
    }

    static boolean isValid(int x, int y) {
        if (x >= 0 && y >= 0 && x < R && y < C) return true;
        return false;
    }
}