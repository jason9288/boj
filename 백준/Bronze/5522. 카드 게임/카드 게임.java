import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += Integer.parseInt(bf.readLine());
        }

        System.out.print(sum);
    }
}

