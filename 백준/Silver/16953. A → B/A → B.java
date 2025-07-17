import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());

        int ans = 1;

        while (B != A) {
            String num = String.valueOf(B);
            if (B > A && B%2 == 0) {
                B /= 2;
                ans++;
            }
            else if (B > A && num.charAt(num.length()-1) == '1') {
                B = Integer.parseInt(num.substring(0, num.length()-1));
                ans++;
            }
            else {
                ans = -1;
                break;
            }
        }
        System.out.println(ans);
    }
}

