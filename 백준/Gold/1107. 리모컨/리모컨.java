import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int target = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        boolean[] broken = new boolean[10];

        if (m > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < m; i++) {
                broken[Integer.parseInt(st.nextToken())] = true;
            }
        }


        int answer = Math.abs(target - 100);
        for (int i = 0; i < 1000000; i++) {
            String num = String.valueOf(i);
            int len = num.length();

            boolean isBroken = false;
            for (int j = 0; j < len; j++) {
                if (broken[num.charAt(j) - '0']) {
                    isBroken = true;
                    break;
                }
            }

            if (!isBroken) {
                int min = Math.abs(target - i) + len;
                answer = Math.min(answer, min);
            }
        }
        System.out.println(answer);
    }
}