import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        long val = 0;
        for (long i = 1L; i <= n-2; i++) {
            val += i*(i+1) / 2;
        }

        System.out.println(val);
        System.out.print("3");
    }
}