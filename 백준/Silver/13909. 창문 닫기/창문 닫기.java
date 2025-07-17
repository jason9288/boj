import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (i*i > n) {
                cnt = i-1;
                break;
            }
        }
        if (cnt == 0) {
            cnt = 1;
        }
        System.out.println(cnt);
    }
}