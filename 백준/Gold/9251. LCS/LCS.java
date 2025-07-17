import java.io.*;

public class Main {
    static int[][] LCS = new int[1001][1001];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s1 = br.readLine();
        String s2 = br.readLine();
        int max = Integer.MIN_VALUE;

        for (int i = 0; i < s1.length()+1; i++) {
            for (int j = 0; j < s2.length()+1; j++) {
                if (i == 0 || j == 0) {
                    LCS[i][j] = 0;
                }
                else if (s1.charAt(i-1) == s2.charAt(j-1)) {
                    LCS[i][j] = LCS[i-1][j-1] + 1;
                }
                else {
                    LCS[i][j] = Math.max(LCS[i-1][j], LCS[i][j-1]);
                }
                if (max < LCS[i][j]) {
                    max = LCS[i][j];
                }
            }
        }
        System.out.println(max);
    }
}