import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    /*
    스도쿠 판 배열:
    0  1  2  3  4  5  6  7  8    --> 0행
    9 10 11 12 13 14 15 16 17 18 --> 1행
    ...
    ...                       80 --> 8행
     */
    static int[][] sudoku = new int[10][10];
    static boolean[][] col = new boolean[10][10]; // 열에 숫자가 존재하는지 체크 ([열][숫자])
    static boolean[][] row = new boolean[10][10]; // 행에 숫자가 존재하는지 체크 ([행][숫자])
    static boolean[][] square = new boolean[10][10]; // n번째 정사각형에 (3X3) 숫자가 존재하는지 체크 ([n번째 정사각형][숫자])

    static int getSqNumber(int x, int y) { // 해당 좌표가 몇 번째 정사각형에 속하는지 구하는 함수
        return (x/3) * 3 + (y/3);
    }
    static boolean go(int z) {
        if (z == 81) { // 모든 칸을 체크한 경우 출력
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    System.out.print(sudoku[i][j] + " ");
                }
                System.out.println();
            }
            return true;
        }
        int x = z / 9; // 해당 칸 번호의 행
        int y = z % 9; // 해당 칸 번호의 열
        if (sudoku[x][y] != 0) { // 해당 칸이 채워져있는 경우
            return go(z + 1); // 다음 칸을 체크
        } else { // 아니면
            for (int i = 1; i <= 9; i++) { // 1~9 의 숫자를 체크하기 위함
                if (!col[x][i] && !row[y][i] && !square[getSqNumber(x, y)][i]) { // 행, 열, 사각형에 숫자가 존재하지 않는 경우
                    col[x][i] = row[y][i] = square[getSqNumber(x, y)][i] = true; // 해당 칸을 i로 채워넣음.
                    sudoku[x][y] = i;
                    if (go(z + 1)) return true; // 다음 칸을 체크 (재귀로서 과정을 반복)
                    sudoku[x][y] = 0; // 다음 숫자 체크에서 실패할 경우 원상복구
                    col[x][i] = row[y][i] = square[getSqNumber(x, y)][i] = false;
                }
            }
        }
        return false; // 실패한 과정에 대해서 false 반환
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < 9; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 9; j++) {
                sudoku[i][j] = Integer.parseInt((st.nextToken()));
                if (sudoku[i][j] != 0) {
                    col[i][sudoku[i][j]] = true;
                    row[j][sudoku[i][j]] = true;
                    square[getSqNumber(i, j)][sudoku[i][j]] = true;
                }
            }
        }
        go(0);
    }
}