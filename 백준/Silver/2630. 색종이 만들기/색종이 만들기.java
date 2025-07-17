import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[][] square;
    static int N;
    static int temp, cnt1, cnt2;
    static boolean checkAll(int x, int y, int size) {
        temp = 0;
        if (square[x][y] == 0) temp = 0;
        if (square[x][y] == 1) temp = 1;
        for (int i = x; i < x+size; i++) {
            for (int j = y; j < y+size; j++) {
                if (square[i][j] == 0 && temp == 1) {
                    return false;
                }
                if (square[i][j] == 1 && temp == 0) {
                    return false;
                }
            }
        }
        return true;
    }

    static void cut(int x, int y, int size) {
        if (!checkAll(x, y, size)) {
            cut(x, y, size/2);
            cut(x+size/2, y, size/2);
            cut(x+size/2, y+size/2, size/2);
            cut(x, y+size/2, size/2);
        } else {
            if (square[x][y] == 1) {
                cnt1++;
            } else {
                cnt2++;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        square = new int[N][N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                square[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        cut(0, 0, N);
        System.out.print(cnt2 +"\n" + cnt1);
    }
}