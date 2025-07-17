import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Stack<Integer> sck = new Stack<>();

        String[] arr = br.readLine().split(" ");

        int min = 1;

        int i = 0;
        boolean chk = true;
        while (true) {
            if (!sck.isEmpty() && min == sck.peek()) {
                sck.pop();
                ++min;
                continue;
            }
            if (i < n) {
                sck.push(Integer.parseInt(arr[i]));
                i++;
            }
            if (sck.isEmpty()) {
                break;
            }
            if (i == n && min < sck.peek()) {
                chk = false;
                break;
            }
        }

        if (chk) {
            System.out.println("Nice");
        } else {
            System.out.println("Sad");
        }
    }
}