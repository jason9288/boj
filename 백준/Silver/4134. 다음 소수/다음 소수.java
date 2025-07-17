import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            long n = Long.parseLong(br.readLine());
            while (!isPrime((n))) {
                n++;
            }
            System.out.println(n);
        }
    }
    public static boolean isPrime(long n) {
        if (n == 1 || n == 0) return false;
        if (n == 2) return true;
        for (int i = 2; i < Math.sqrt(n)+1; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
}