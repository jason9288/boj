import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());
        String S = br.readLine();
        int[] oi = new int[M];
        int ans = 0;

        for (int i = 1; i < M-1; i++) {
            if (S.charAt(i) == 'O' && S.charAt(i+1) == 'I') {
                oi[i+1] = oi[i-1] + 1;

                if (oi[i+1] >= N && S.charAt((i+1) - (N*2)) == 'I') {
                    ans++;
                }
            }
        }
        System.out.println(ans);
    }
}