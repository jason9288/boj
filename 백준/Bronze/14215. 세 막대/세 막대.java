import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int[] l = new int[3];
        for (int i = 0; i < 3; i++) {
            l[i] = Integer.parseInt(input[i]);
        }
        Arrays.sort(l);

        int sum = 0;

        while (l[2] >= l[1] + l[0]) {
            l[2]--;
        }
        sum += l[0] + l[1] + l[2];


        System.out.println(sum);
    }
}