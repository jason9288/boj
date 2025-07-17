import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = "";
        while ((s = br.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(s);
            int n = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if (n == 0 && b == 0) {
                break;
            } else {
                if (n > b) {
                    System.out.println("Yes");
                } else {
                    System.out.println("No");
                }
            }
        }

    }
}

