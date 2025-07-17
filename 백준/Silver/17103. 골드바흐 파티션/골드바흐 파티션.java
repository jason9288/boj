import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        ArrayList<Boolean>primeArr = new ArrayList<>(1000001);
        isPrime(primeArr);

        for (int i = 0; i < t; i++) {
            int cnt = 0;
            int n = Integer.parseInt(br.readLine());
            for (int j = 0; j < n/2 + 1; j++) {
                if (primeArr.get(j) && primeArr.get(n-j)) {
                    cnt++;
                }
            }
            System.out.println(cnt);
        }
    }
    public static void isPrime(ArrayList<Boolean> arr) {
        for (int i = 0; i <= 1000000; i++) {
            arr.add(true);
        }
        for (int i = 2; i <= Math.sqrt(1000000); i++) {
            if (arr.get(i)) {
                int j = 2;
                while (i*j <= 1000000) {
                    arr.set(i*j, false);
                    j++;
                }
            }
        }
        arr.set(0, false);
        arr.set(1, false);
    }
}