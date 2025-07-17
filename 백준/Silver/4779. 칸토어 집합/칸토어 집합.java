import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int n;
    static StringBuilder ans;
    static void cantor(int st, int size) {
        if (size == 1) {
            return;
        }
        int newSize = size/3;
        for (int i = st+newSize; i <st+2*newSize; i++) {
            ans.setCharAt(i, ' ');
        }
        cantor(st, newSize);
        cantor(st+2*newSize, newSize);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input;
        while ((input = br.readLine()) != null) {
            int n = Integer.parseInt(input);
            ans = new StringBuilder();
            int len = (int) Math.pow(3, n);

            for (int i = 0; i < len; i++) {
                ans.append('-');
            }

            cantor(0, len);
            System.out.println(ans);
        }
    }
}