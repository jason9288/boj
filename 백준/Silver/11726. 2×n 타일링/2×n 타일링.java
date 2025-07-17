import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static long tiling(int size, long[] memo) {
        if (size <= 1) {
            return 1;
        }
        if (memo[size] != 0) {
            return memo[size];
        }
        memo[size] = ((tiling(size-1, memo))%10007 + (tiling(size-2, memo))%10007 )%10007;
        return memo[size];
    }

    public static void main(String[] args) throws IOException {
        long[] memo = new long[1001];

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bf.readLine());

        long res = tiling(n, memo);

        System.out.print(res);
    }
}