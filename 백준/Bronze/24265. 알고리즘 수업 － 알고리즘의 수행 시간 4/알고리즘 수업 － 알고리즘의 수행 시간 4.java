import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        long val = 0L;
        for (int i = 1; i < n; i++) {
            val += i;
        }

        System.out.println(val);
        System.out.print("2");
    }
}