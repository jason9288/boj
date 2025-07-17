import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] trees = new int[n];
        for (int i = 0; i < n; i++) {
            trees[i] = Integer.parseInt(br.readLine());
        }

        int g = 0;

        for (int i = 0; i < n-1; i++) {
            int dist = trees[i+1] - trees[i];
            g = gcd(dist, g);
        }

        int num_trees = ((trees[n-1] - trees[0]) / (g) +1 -n);
        System.out.print(num_trees);
    }

    static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a%b);
    }
}